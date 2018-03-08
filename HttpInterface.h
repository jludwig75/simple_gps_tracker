#pragma once

#include <WString.h>


class HttpInterface
{
public:
  virtual ~HttpInterface() {}
  virtual int post(const char* aURLPath, const char* aContentType, const char* aBody) = 0;
  virtual int post(const String& aURLPath, const String& aContentType, const String& aBody) = 0;
  
  virtual int responseStatusCode() = 0;
};

