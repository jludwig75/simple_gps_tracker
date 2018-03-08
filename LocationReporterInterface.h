#pragma once
#include "GpsLocation.h"

class HttpInterface;


class LocationReporterInterface
{
public:
  virtual const char *get_server_name() const = 0;
  virtual unsigned short get_server_port() const = 0;
  virtual bool update_location(HttpInterface *http, const GpsLocation & location) = 0;
};
