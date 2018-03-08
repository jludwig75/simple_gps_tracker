#pragma once

#include "LocationReporterInterface.h"
#include "GpsInterface.h"
#include "GsmInterface.h"


class LocationTracker
{
public:
  LocationTracker(GpsInterface *gps, GsmInterface *gsm, LocationReporterInterface *location_reporter, unsigned long update_interval_ms);
  void on_loop();
private:
  GpsInterface *_gps;
  GsmInterface *_gsm;
  LocationReporterInterface *_location_reporter;
  long _update_interval_ms;
  long _last_update_time;
};

