#pragma once
#include "GsmInterface.h"


class FakeGsm : public GsmInterface
{
public:
  FakeGsm();
  virtual bool connect_gprs(unsigned long timeout);
  virtual bool disconnect_gprs();
  
  virtual HttpInterface *connect_http(const char *server, unsigned short port);
private:
  bool _gsm_connected;  
};
