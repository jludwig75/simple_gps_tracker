#pragma once
#include "GsmInterface.h"

#include <SoftwareSerial.h>

#define TINY_GSM_MODEM_A7
#include <TinyGsmClient.h>


class GsmDevice : public GsmInterface
{
public:
  GsmDevice(int gsm_rx, int gsm_tx, const char *apn, const char *user, const char *pwd, bool debug_at_commands = false);

  bool begin(int baud_rate);

  virtual bool connect_gprs(unsigned long timeout);
  virtual bool disconnect_gprs();
  
  virtual HttpInterface *connect_http(const char *server, unsigned short port);
  
private:
  const char *_apn;
  const char *_user;
  const char *_pwd;
  SoftwareSerial _serialAT;
  TinyGsm _modem;
  TinyGsmClient _client;
};

