#pragma once
#include "GpsLocation.h"


class GpsInterface
{
public:
  virtual ~GpsInterface() {}
  virtual bool location_valid() const = 0;
  virtual unsigned long location_age() const = 0;
  virtual GpsLocation get_location() const = 0;

  virtual void process_gps_data() = 0;

};

