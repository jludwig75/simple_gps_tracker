#pragma once
#include "GpsInterface.h"

class TinyGPSPlus;
class SoftwareSerial;


class GpsDevice : public GpsInterface
{
public:
  GpsDevice(int gps_rx, int gps_tx);
  ~GpsDevice();

  void begin(int baud_rate = 4800);
  
  virtual bool location_valid() const;
  virtual unsigned long location_age() const;
  virtual GpsLocation get_location() const;

  virtual void process_gps_data();
private:
  TinyGPSPlus *_gps;  
  SoftwareSerial *_ss;
};

