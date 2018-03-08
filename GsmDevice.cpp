#include "GsmDevice.h"

#include <ArduinoHttpClient.h>
#include "ArduinoHttpConnection.h"


GsmDevice::GsmDevice(int gsm_rx, int gsm_tx, const char *apn, const char *user, const char *pwd, bool debug_at_commands) : _apn(apn), _user(user), _pwd(pwd), _serialAT(gsm_rx, gsm_tx), _modem(_serialAT), _client(_modem)
{
  
}

bool GsmDevice::begin(int baud_rate)
{
  // Set GSM module baud rate
  _serialAT.begin(baud_rate);

  delay(3000);

  // Initialize the GSM device
  Serial.println("Initializing modem...");
  while (!_modem.init())
  {
    Serial.println("Failed to initialize GSM device. Retrying...");
    delay(1000);
  }

  String modemInfo = _modem.getModemInfo();
  Serial.print("Modem: ");
  Serial.println(modemInfo);

  return true;
}

bool GsmDevice::connect_gprs(unsigned long timeout)
{
  if (!_modem.waitForNetwork(timeout))
  {
    return false;
  }

  if (!_modem.gprsConnect(_apn, _user, _pwd))
  {
    return false;
  }

  return true;
}

bool GsmDevice::disconnect_gprs()
{
  return _modem.gprsDisconnect();
}

HttpInterface *GsmDevice::connect_http(const char *server, unsigned short port)
{
  
  HttpClient *http = new HttpClient(_client, server, port);
  if (!http)
  {
    return NULL;
  }

  HttpInterface *http_int = new ArduinoHttpConnection(http);
  if (!http_int)
  {
    delete http;
    return NULL;
  }

  return http_int;
}

