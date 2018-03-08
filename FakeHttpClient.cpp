#include "FakeHttpClient.h"


FakeHttpClient::FakeHttpClient(Client &aClient) : HttpClient(aClient, "", 0)
{
  
}

int FakeHttpClient::post(const char* aURLPath, const char* aContentType, const char* aBody)
{
  return post((const char *)aURLPath, (const char *)aContentType, strlen(aBody), (const char *)aBody);
}

int FakeHttpClient::post(const String& aURLPath, const String& aContentType, const String& aBody)
{
  return post(aURLPath.c_str(), aContentType.c_str(), aBody.length(), aBody.c_str());
}

int FakeHttpClient::post(const char* aURLPath, const char* aContentType, int aContentLength, const byte aBody[])
{
  Serial.print("POST to \"");
  Serial.print(aURLPath);
  Serial.print("\": \"");
  Serial.print(aContentType);
  Serial.print("\", \"");
  Serial.print((const char *)aBody);  // This only works for text bodies, which is all I care about for this project.
  Serial.println("\"");
  return 0;
}

int FakeHttpClient::responseStatusCode();

