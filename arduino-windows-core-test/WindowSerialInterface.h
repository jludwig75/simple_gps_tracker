#pragma once


#include <stdint.h>

class WindowsSerialInterface
{
public:
    WindowsSerialInterface(unsigned com_port_number);
    ~WindowsSerialInterface();
    bool read_byte(unsigned char *byte);
    bool write_byte(unsigned char byte);
private:
    unsigned _com_port_number;
    void *_handle;
    void *_ov_event;
};
