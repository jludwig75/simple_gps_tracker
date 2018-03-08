#pragma once

class HttpClient;


class GsmInterface
{
public:
  virtual ~GsmInterface() {}
  virtual bool connect_gprs(unsigned long timeout = 60000L) = 0;
  virtual bool disconnect_gprs() = 0;
  
  virtual HttpClient *connect_http(const char *server, unsigned short port) = 0;
  
};

