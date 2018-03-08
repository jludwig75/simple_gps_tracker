#include "GpsDevice.h"

#include <SoftwareSerial.h>
#include <TinyGPS++.h>


GpsDevice::GpsDevice(int gps_rx, int gps_tx) : _gps(NULL), _ss(NULL)
{
  _ss = new SoftwareSerial(gps_rx, gps_tx);
  _gps = new TinyGPSPlus();
}

GpsDevice::~GpsDevice()
{
  delete _gps;
  delete _ss;
}

void GpsDevice::begin(int baud_rate)
{
  _ss->begin(baud_rate);
}

bool GpsDevice::location_valid() const
{
  return _gps->location.isValid();
}

unsigned long GpsDevice::location_age() const
{
  return _gps->location.age();
}

GpsLocation GpsDevice::get_location() const
{
  if (!_gps->location.isValid())
  {
    return GpsLocation();
  }

  return GpsLocation(_gps->location.age(), _gps->location.lat(), _gps->location.lng(), 0);
}

void GpsDevice::process_gps_data()
{
  while (_ss->available() > 0)
  {
    _gps->encode(_ss->read());
  }
}

