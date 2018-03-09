#include "WindowSerialInterface.h"

#include <string>
#include <sstream>

#include <Windows.h>
#include <assert.h>
#include <conio.h>


using namespace std;


WindowsSerialInterface::WindowsSerialInterface(unsigned com_port_number) : _com_port_number(com_port_number), _handle(NULL)
{
    if (com_port_number == 0)
    {
        return;
    }

    stringstream ss;
    ss << "COM" << com_port_number;
    string port_name = ss.str();

    _handle = CreateFileA(port_name.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    if (!_handle || _handle == INVALID_HANDLE_VALUE)
    {
        throw GetLastError();
    }

    _ov_event = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (!_ov_event)
    {
        CloseHandle(_handle);
        _handle = NULL;
        throw GetLastError();
    }
}

WindowsSerialInterface::~WindowsSerialInterface()
{
    if (_handle && _handle != INVALID_HANDLE_VALUE)
    {
        CloseHandle(_handle);
    }
}

bool WindowsSerialInterface::read_byte(unsigned char *byte)
{
    if (_com_port_number == 0)
    {
        if (_kbhit())
        {
            *byte = getch();
            return true;
        }

        return false;
    }

    DWORD bytes_read;
    OVERLAPPED ov = { 0 };
    ov.hEvent = _ov_event;
    if (!ReadFile(_handle, byte, 1, &bytes_read, &ov))
    {
        if (GetLastError() != ERROR_IO_PENDING)
        {
            return false;
        }

        while (true)
        {
            DWORD ret = WaitForSingleObject(_ov_event, INFINITE);
            if (ret == WAIT_OBJECT_0)
            {
                if (!GetOverlappedResult(_handle, &ov, &bytes_read, FALSE))
                {
                    return false;
                }

                assert(bytes_read == 1);
                return true;
            }
            else if (ret != WAIT_TIMEOUT)
            {
                return false;
            }
        }
    }

    assert(bytes_read == 1);
    return true;
}

bool WindowsSerialInterface::write_byte(unsigned char byte)
{
    if (_com_port_number == 0)
    {
        putc(byte, stdout);
        return true;
    }

    DWORD bytes_written;
    OVERLAPPED ov = { 0 };
    ov.hEvent = _ov_event;
    if (!WriteFile(_handle, &byte, 1, &bytes_written, &ov))
    {
        if (GetLastError() != ERROR_IO_PENDING)
        {
            return false;
        }

        while (true)
        {
            DWORD ret = WaitForSingleObject(_ov_event, INFINITE);
            if (ret == WAIT_OBJECT_0)
            {
                if (!GetOverlappedResult(_handle, &ov, &bytes_written, FALSE))
                {
                    return false;
                }

                assert(bytes_written == 1);
                return true;
            }
            else if (ret != WAIT_TIMEOUT)
            {
                return false;
            }
        }
    }

    assert(bytes_written == 1);
    return true;
}

