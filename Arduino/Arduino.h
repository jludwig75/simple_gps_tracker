#pragma once

#include <WString.h>


class HardwareSerial
{
public:
    void print(const String &str);
    void println(const String &str);
    void print(const char *str);
    void println(const char *str);
    void print(double val);
    void println(double val);
    void print(unsigned long val);
    void println(unsigned long val);

};

long millis();

extern HardwareSerial Serial;