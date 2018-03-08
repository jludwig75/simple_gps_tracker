#pragma once
#include "LocationReporterInterface.h"


class LocationReporter : public LocationReporterInterface
{
public:
  LocationReporter(const char *server, unsigned short port, const char *location_server_report_path);
  
  virtual const char *get_server_name() const;
  virtual unsigned short get_server_port() const;
  virtual bool update_location(HttpInterface *http, const GpsLocation & location);
private:
  const char *_server;
  unsigned short _port;
  const char *_location_server_report_path;
};

