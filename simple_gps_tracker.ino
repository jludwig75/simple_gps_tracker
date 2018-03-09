#define SIM_WITH_FAKES
#include "LocationTrackerApp.h"


const long update_interval_ms = 10 * 1000;
const int gsm_rx = 1;
const int gsm_tx = 2;
const int gps_rx = 3;
const int gps_tx = 4;

const char *gsm_apn = "sdfds";
const char *gsm_user = "";
const char *gsm_pwd = "";

const char *location_server = "";
unsigned short location_server_port = 0;
const char *location_server_report_path = "/report_location";


LocationTrackerApp app(gps_rx, gps_tx,
                       gsm_rx, gsm_tx,
                       gsm_apn, gsm_user, gsm_pwd,
                       true,
                       location_server, location_server_port, location_server_report_path,
                       update_interval_ms);

void setup()
{
  Serial.begin(115200);

  app.setup();
}

void loop() {
  app.loop();
}
