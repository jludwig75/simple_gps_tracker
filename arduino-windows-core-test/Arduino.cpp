#include <stdio.h>
#include <string.h>

#include <Windows.h>

extern "C" void setup();
extern "C" void loop();

int main(int argc, char *argv[])
{
    setup();
    while (true)
    {
        loop();
    }
    return 0;
}

extern "C" char *strcpy_P(char *d, const char *s)
{
    return strcpy(d, s);
}

extern "C" size_t __strlen_P(const char *s)
{
    return strlen(s);
}

long program_start_tick = GetTickCount();

extern "C" long millis()
{
    return GetTickCount() - program_start_tick;
}