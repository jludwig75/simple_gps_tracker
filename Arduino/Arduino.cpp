#include "Arduino.h"

#include <stdio.h>
#include <Windows.h>


void HardwareSerial::print(const String &str)
{
    printf(str.c_str());
}

void HardwareSerial::println(const String &str)
{
    printf("%s\n", str.c_str());
}

void HardwareSerial::print(const char *str)
{
    printf(str);
}

void HardwareSerial::println(const char *str)
{
    printf("%s\n", str);
}

void HardwareSerial::print(double val)
{
    printf("%f", val);
}

void HardwareSerial::println(double val)
{
    printf("%f\n", val);
}

void HardwareSerial::print(unsigned long val)
{
    printf("%lu", val);
}

void HardwareSerial::println(unsigned long val)
{
    printf("%lu\n", val);
}


long program_start_tick = GetTickCount();

long millis() { return GetTickCount() - program_start_tick; }

HardwareSerial Serial;