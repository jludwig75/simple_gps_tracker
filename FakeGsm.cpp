#include "FakeGsm.h"
#include "FakeHttpConnection.h"


FakeGsm::FakeGsm() : _gsm_connected(false)
{
  
}

bool FakeGsm::connect_gprs(unsigned long timeout)
{
  if (_gsm_connected)
  {
    return false;
  }

  _gsm_connected = true;
  return true;
}

bool FakeGsm::disconnect_gprs()
{
  if (!_gsm_connected)
  {
    return false;
  }

  _gsm_connected = false;
  return true;
}

HttpInterface *FakeGsm::connect_http(const char *server, unsigned short port)
{
  return new FakeHttpConnection();
}

