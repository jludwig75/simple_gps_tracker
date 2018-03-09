#pragma once
#ifdef SIM_WITH_FAKES
#include "FakeGps.h"
#include "FakeGsm.h"
#else  // SIM_WITH_FAKES
#include "GpsDevice.h"
#include "GsmDevice.h"
#endif // SIM_WITH_FAKES

#include "LocationReporter.h"
#include "LocationTracker.h"


class LocationTrackerApp
{
public:
  LocationTrackerApp(int gps_rx, int gps_tx, int gsm_rx, int gsm_tx, const char *gsm_apn, const char *gsm_user, const char *gsm_pwd, bool debug_at_commands, const char *location_server, unsigned short location_server_port, const char *location_server_report_path, unsigned long update_interval_ms);

  void setup();
  void loop();

private:  
#ifdef SIM_WITH_FAKES
    FakeGps _gps;
    FakeGsm _gsm;
#else  // SIM_WITH_FAKES
    GpsDevice _gps;
    GsmDevice _gsm;
#endif // SIM_WITH_FAKES
  LocationReporter _reporter;
  LocationTracker _tracker;
};

