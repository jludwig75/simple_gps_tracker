#include "FakeGps.h"

double dummy_coordinates[][3] = {
  {40.4667980, -111.7531490, 1612.2},
  {40.4667630, -111.7531270, 1612.2},
  {40.4667260, -111.7531170, 1612.3},
  {40.4666990, -111.7531050, 1612.3},
  {40.4666690, -111.7530910, 1612.4},
  {40.4666370, -111.7530880, 1612.5},
  {40.4665960, -111.7530830, 1612.5},
  {40.4665610, -111.7530870, 1612.5}
};

FakeGps::FakeGps() : _canned_locations(), _next_canned_location(0)
{
  for(unsigned i = 0; i < NUM_CANNED_LOCATIONS; i++)
  {
    _canned_locations[i] = GpsLocation(0, dummy_coordinates[i][0], dummy_coordinates[i][1], dummy_coordinates[i][2]);
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
  GpsLocation loc = _canned_locations[_next_canned_location];
  _next_canned_location = (_next_canned_location + 1) % NUM_CANNED_LOCATIONS;

  return loc;
}

void FakeGps::process_gps_data()
{
}

