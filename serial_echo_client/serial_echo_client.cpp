#include <Arduino.h>
#include <HardwareSerial.h>



void setup()
{
    Serial.begin(9600);

    Serial.println("Starting sketch.");
    Serial.print("Enter something: ");
    Serial.setTimeout(20000);
    String s = Serial.readString();
    Serial.println("");
    Serial.print("You entered ");
    Serial.println(s);

    Serial1.begin(9600);
}

void loop()
{
    if (Serial1.available())
    {
        Serial.write(Serial1.read());
    }

    if (Serial.available())
    {
        Serial1.write(Serial.read());
    }
}
