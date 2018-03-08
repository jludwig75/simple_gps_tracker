#include "LocationReporter.h"

#include <ArduinoHttpClient.h>


LocationReporter::LocationReporter(const char *server, unsigned short port, const char *location_server_report_path) : _server(server), _port(port), _location_server_report_path(location_server_report_path)
{
  
}

const char *LocationReporter::get_server_name() const
{
  return _server;
}

unsigned short LocationReporter::get_server_port() const
{
  return _port;
}


bool LocationReporter::update_location(HttpClient *http, const GpsLocation & location)
{
  Serial.print("Location: lat=");
  Serial.print(location.latitude);
  Serial.print(", lon=");
  Serial.print(location.longitude);
  Serial.print(", alt=");
  Serial.print(location.altitude);
  Serial.print(", age=");
  Serial.print(location.age);
  Serial.println(" ms");

  // Do HTTP POST
  String contentType = "application/x-www-form-urlencoded";
  String postData = "latitude=" + String(location.latitude) + "&longitude=" + String(location.longitude) + "&altitude=" + String(location.altitude) + "&age=" + String(location.age);

  Serial.print("POST: \"");
  Serial.print(postData);
  Serial.println("\"");
  
  http->post("/", contentType, postData);

  return http->responseStatusCode() == 200;
}

