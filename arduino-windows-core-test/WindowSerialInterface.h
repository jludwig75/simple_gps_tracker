#pragma once


#include <stdint.h>

class WindowsSerialInterface
{
public:
    WindowsSerialInterface(unsigned com_port_number);
    ~WindowsSerialInterface();
    bool open(unsigned long baud);
    bool read_byte(unsigned char *byte);
    bool write_byte(unsigned char byte);
private:
    void *_handle;
    void *_ov_event;
};
