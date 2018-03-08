#pragma once


#include "HttpInterface.h"


class GsmInterface
{
public:
  virtual ~GsmInterface() {}
  virtual bool connect_gprs(unsigned long timeout = 60000L) = 0;
  virtual bool disconnect_gprs() = 0;
  
  virtual HttpInterface *connect_http(const char *server, unsigned short port) = 0;
  
};

