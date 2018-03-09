#include <Arduino.h>
#include <HardwareSerial.h>



void setup()
{
    Serial1.begin(9600);
    Serial3.begin(9600);
}

void loop()
{
    while (Serial1.available())
    {
        Serial3.write(Serial1.read());
    }
}
