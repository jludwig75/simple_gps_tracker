#include "ArduinoHttpConnection.h"

#include <ArduinoHttpClient.h>

ArduinoHttpConnection::ArduinoHttpConnection(HttpClient *client) : _client(client)
{
  
}

ArduinoHttpConnection::~ArduinoHttpConnection()
{
  delete _client;
}



int ArduinoHttpConnection::post(const char* aURLPath, const char* aContentType, const char* aBody)
{
  return _client->post(aURLPath, aContentType, aBody);
}

int ArduinoHttpConnection::post(const String& aURLPath, const String& aContentType, const String& aBody)
{
  return _client->post(aURLPath, aContentType, aBody);
}
  
int ArduinoHttpConnection::responseStatusCode()
{
  return _client->responseStatusCode();
}

