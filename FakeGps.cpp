#include "FakeGps.h"


FakeGps::FakeGps() : _canned_locations(), _next_canned_location(0)
{
  for(unsigned i = 0; i < NUM_CANNED_LOCATIONS; i++)
  {
    _canned_locations[i] = GpsLocation(); // TODO: Initialize with real coordinates. 
  }
}

bool FakeGps::location_valid() const
{
  return true;
}

unsigned long FakeGps::location_age() const
{
  return 0;
}

GpsLocation FakeGps::get_location() const
{
  return _canned_locations[_next_canned_location];
  _next_canned_location = (_next_canned_location + 1) % NUM_CANNED_LOCATIONS;
}

void FakeGps::process_gps_data()
{
}

