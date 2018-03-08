#include "FakeHttpConnection.h"

int FakeHttpConnection::post(const char* aURLPath, const char* aContentType, const char* aBody)
{
  return 0;
}

int FakeHttpConnection::post(const String& aURLPath, const String& aContentType, const String& aBody)
{
  return 0;
}

int FakeHttpConnection::responseStatusCode()
{
  return 200;
}

