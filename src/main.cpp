#include <Arduino.h>

#include "cTemperatureSensor.h"
#include <OneWire.h>           //One Wire Temperature
#include <DallasTemperature.h> //One Wire Temperature

//DS18B20 = name of Sensor
#define CountOfSensors_DS18B20 2

void initSerialSetup()
{
    Serial.begin(9600);
    Serial.println("TemperatureBasicTest");
    Serial.println();
    delay(100);
    Serial.print("Anzahl aktivierter Sensoren: ");
    Serial.println(CountOfSensors_DS18B20);
}

float Temperature1;
float Temperature2;

cTemperatureSensor Temperature;

///Pin Defines
#define BUSINPUT_PIN D1 //Bus wire for Tempreture

void setup()
{

    initSerialSetup();
    pinMode(BUSINPUT_PIN, INPUT);
    Temperature.init(CountOfSensors_DS18B20, BUSINPUT_PIN);
    // Temperature2 = digitalRead(BUSINPUT_PIN);
}

void loop()
{
    // put your main code here, to run repeatedly:

    String Temperature1Str;
    String Temperature2Str;

//-1 == ok else index of failed sensor
int indexOfFailedSensor = Temperature.updateTemperature();

    if(indexOfFailedSensor == -1) 
    {
        Temperature1 = Temperature.getValueByIndex(0);
        if (Temperature1 < 100 && Temperature1 > -1)
        {
            Temperature1Str = String(Temperature1) + " �C";
        }
        else
        {
            Temperature1Str = "Error";
        }
        Temperature2 = Temperature.getValueByIndex(1);

        if (Temperature2 < 100 && Temperature2 > -1)
        {
            Temperature2Str = String(Temperature2) + " �C";
        }
        else
        {
            Temperature2Str = "Error";
        }
    }
    else
    {

        Serial.print("updateTemperatur() failed index:");
        Serial.println(indexOfFailedSensor);
    }

}
