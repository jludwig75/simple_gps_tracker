#include "LocationTracker.h"

#include <Arduino.h>


LocationTracker::LocationTracker(GpsInterface *gps, GsmInterface *gsm, LocationReporterInterface *location_reporter, unsigned long update_interval_ms) :
  _gps(gps),
  _gsm(gsm),
  _location_reporter(location_reporter),
  _update_interval_ms(update_interval_ms),
  _last_update_time(0)
{
}

void LocationTracker::on_loop()
{
  _gps->process_gps_data();

  if (millis() - _last_update_time >= _update_interval_ms)
  {
    if (_gps->location_valid())
    {
      if (!_gsm->connect_gprs())
      {
        Serial.println("Failed to connect GPRS");
        return;
      }
    
      HttpInterface *http = _gsm->connect_http(_location_reporter->get_server_name(), _location_reporter->get_server_port());
      if (!http)
      {
        _gsm->disconnect_gprs();
        Serial.println("Could not connect to location server.");
        return;
      }
  
      if (_location_reporter->update_location(http, _gps->get_location()))
      {
        // Only reset the update interval on success so we keep trying on failure.
        _last_update_time = millis();
        Serial.println("Successfully updated location with location database.\n");
      }
      else
      {
        Serial.println("Failed to update location with location database.\n");
      }
    
      _gsm->disconnect_gprs();
    }
  }
}

