#include "LocationTrackerApp.h"


LocationTrackerApp::LocationTrackerApp(int gps_rx, int gps_tx, int gsm_rx, int gsm_tx, const char *gsm_apn, const char *gsm_user, const char *gsm_pwd, bool debug_at_commands, const char *location_server, unsigned short location_server_port, const char *location_server_report_path, unsigned long update_interval_ms) :
  //_gps(gps_rx, gps_tx),
  _gps(),
  //_gsm(gsm_rx, gsm_tx, gsm_apn, gsm_user, gsm_pwd, debug_at_commands),
  _gsm(),
  _reporter(location_server, location_server_port, location_server_report_path),
  _tracker(&_gps, &_gsm, &_reporter, update_interval_ms)
{
  
}

void LocationTrackerApp::setup()
{
  //_gps.begin(4800);


  //while (!_gsm.begin(115200))
  //{
  //  Serial.println("Failed to start location tracker. Retrying...\n");
  //  delay(1000);
  //}
}

void LocationTrackerApp::loop()
{
  _tracker.on_loop();
}

