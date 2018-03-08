#pragma once
//#include "GpsDevice.h"
//#include "GsmDevice.h"
#include "LocationReporter.h"
#include "LocationTracker.h"

#include "FakeGps.h"
#include "FakeGsm.h"

class LocationTrackerApp
{
public:
  LocationTrackerApp(int gps_rx, int gps_tx, int gsm_rx, int gsm_tx, const char *gsm_apn, const char *gsm_user, const char *gsm_pwd, bool debug_at_commands, const char *location_server, unsigned short location_server_port, const char *location_server_report_path, unsigned long update_interval_ms);

  void setup();
  void loop();

private:  
  //GpsDevice _gps;
  FakeGps _gps;
  //GsmDevice _gsm;
  FakeGsm _gsm;
  LocationReporter _reporter;
  LocationTracker _tracker;
};

