#pragma once

#include "HttpInterface.h"

class FakeHttpConnection : public HttpInterface
{
public:
  virtual int post(const char* aURLPath, const char* aContentType, const char* aBody);
  virtual int post(const String& aURLPath, const String& aContentType, const String& aBody);
  
  virtual int responseStatusCode();
};
