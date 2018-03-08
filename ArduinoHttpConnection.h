#pragma once
#include "HttpInterface.h"

class HttpClient;

class ArduinoHttpConnection : public HttpInterface
{
public:
  ArduinoHttpConnection(HttpClient *client);
  ~ArduinoHttpConnection();
  virtual int post(const char* aURLPath, const char* aContentType, const char* aBody);
  virtual int post(const String& aURLPath, const String& aContentType, const String& aBody);

  virtual int responseStatusCode();
private:
  HttpClient *_client;
};

