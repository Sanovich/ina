#include <Arduino.h>
#include <Wire.h>
#include "SDL_Arduino_INA3221.h"

SDL_Arduino_INA3221 ina3221; // создаём экземпляр класса датчика

// Три канала измерения датчика INA3221
#define CHANNEL_1 1
#define CHANNEL_2 2
#define CHANNEL_3 3

void setup(void)
{
  Serial.begin(115200);
  Serial.println("Arduino INA3221 test");
  ina3221.begin();

  Serial.print("ID=0x");
  int id = ina3221.getManufID();
  Serial.println(id, HEX);

  Serial.println("Measuring voltage and current with ina3221 ...");
}

void loop(void)
{
  Serial.println("---------------------------------------------");
  Serial.println("Channel:\t\t(1)\t(2)\t(3)\t"); // "\t" - это символ табуляции

  // Вывод напряжений по трём каналам:
  Serial.print("Bus voltage, V: \t");
  float busvoltage1 = ina3221.getBusVoltage_V(CHANNEL_1);
  float busvoltage2 = ina3221.getBusVoltage_V(CHANNEL_2);
  float busvoltage3 = ina3221.getBusVoltage_V(CHANNEL_3);
  Serial.print(busvoltage1); Serial.print("\t");
  Serial.print(busvoltage2); Serial.print("\t");
  Serial.print(busvoltage3); Serial.println("\t");

  // Вывод напряжений на шунте по трём каналам:
  Serial.print("Shunt voltage, mV: \t");
  float shuntvoltage1 = ina3221.getShuntVoltage_mV(CHANNEL_1);
  float shuntvoltage2 = ina3221.getShuntVoltage_mV(CHANNEL_2);
  float shuntvoltage3 = ina3221.getShuntVoltage_mV(CHANNEL_3);
  Serial.print(shuntvoltage1); Serial.print("\t");
  Serial.print(shuntvoltage2); Serial.print("\t");
  Serial.print(shuntvoltage3); Serial.println("\t");

  // Вывод напряжений нагрузки по трём каналам:
  Serial.print("Load voltage, V: \t");
  float loadvoltage1 = busvoltage1 + (shuntvoltage1 / 1000);
  float loadvoltage2 = busvoltage2 + (shuntvoltage2 / 1000);
  float loadvoltage3 = busvoltage3 + (shuntvoltage3 / 1000);
  Serial.print(loadvoltage1); Serial.print("\t");
  Serial.print(loadvoltage2); Serial.print("\t");
  Serial.print(loadvoltage3); Serial.println("\t");

  // Вывод тока по трём каналам:
  Serial.print("Current, mA: \t\t");
  float current_mA1 = ina3221.getCurrent_mA(CHANNEL_1);
  float current_mA2 = ina3221.getCurrent_mA(CHANNEL_2);
  float current_mA3 = ina3221.getCurrent_mA(CHANNEL_3);
  Serial.print(current_mA1); Serial.print("\t");
  Serial.print(current_mA2); Serial.print("\t");
  Serial.print(current_mA3); Serial.println("\t");

  delay(2000);
}
