#pragma once

#include <DallasTemperature.h>
class cTemperatureSensor
{
public:
    cTemperatureSensor();
    ~cTemperatureSensor();

    void init(int _countOfSensors, int _BusInputPIN);
    
    
    //Return true if ok -> else false 
    int updateTemperature();

    const float No_Val = 999.99;
    OneWire             m_oneWire;
    DallasTemperature   m_DS18B20;
    DeviceAddress       m_DS18B20_Adressen;
    int m_countOfSensors;
    static const int m_DS18B20_Aufloesung = 12;

    float* m_pValues;

    float getValueByIndex(int _index);

};
