#pragma once


class GpsLocation
{
public:
  GpsLocation(unsigned long age, double longitude, double latitude, double altitude) : age(age), longitude(longitude), latitude(latitude), altitude(altitude)
  {
    
  }
  // TODO: Handle invalid location field values and add an is_valid method
  GpsLocation() : age(10000000), longitude(360), latitude(360), altitude(-10000)
  {
    
  }
  unsigned long age;
  double longitude;
  double latitude;
  double altitude;
};

