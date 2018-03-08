#pragma once


#include <string>
#include <sstream>


template<typename _T>
std::string ToString(_T & t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}


class String : public std::string
{
public:
    String(const std::string &str) : std::string(str) {}
    String(const char *str) : std::string(str) {}
    String(const String &str) : std::string(str) {}
    String(unsigned long val) : std::string(ToString(val)) {}
    String(double val) : std::string(ToString(val)) {}
};
