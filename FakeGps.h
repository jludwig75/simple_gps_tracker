#pragma once
#include "GpsInterface.h"


#define NUM_CANNED_LOCATIONS  8

class FakeGps : public GpsInterface
{
public:
  FakeGps();
  virtual bool location_valid() const;
  virtual unsigned long location_age() const;
  virtual GpsLocation get_location() const;

  virtual void process_gps_data();
private:
  GpsLocation _canned_locations[NUM_CANNED_LOCATIONS];
  mutable unsigned _next_canned_location;
};

