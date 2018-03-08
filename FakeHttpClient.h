#pragma once
#include <ArduinoHttpClient.h>


class DummyClient : public Client
{
  virtual int connect(IPAddress ip, uint16_t port)
  {
    return 0;
  }
  virtual int connect(const char *host, uint16_t port)
  {
    return 0;
  }
  virtual size_t write(uint8_t)
  {
    return 0;
  }
  virtual size_t write(const uint8_t *buf, size_t size)
  {
    return 0;
  }
  virtual int available()
  {
    return 0;
  }
  virtual int read()
  {
    return 0;
  }
  virtual int read(uint8_t *buf, size_t size)
  {
    return 0;
  }
  virtual int peek()
  {
    return 0;
  }
  virtual void flush()
  {
  }
  virtual void stop()
  {
  }
  virtual uint8_t connected()
  {
    return 0;
  }
  virtual operator bool()
  {
    return false;
  }
};

class FakeHttpClient : public HttpClient
{
public:
  FakeHttpClient(Client &aClient);
  int post(const char* aURLPath, const char* aContentType, const char* aBody);
  int post(const String& aURLPath, const String& aContentType, const String& aBody);

  int responseStatusCode();
private:
  // Can't really support this now.  
  int post(const char* aURLPath, const char* aContentType, int aContentLength, const byte aBody[]);
};
