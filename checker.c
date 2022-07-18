#include <stdio.h>
#include <assert.h>
#include "batteryCheck.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
  BatteryParameters parameters;
  parameters.temperature = temperature;
  parameters.soc = soc;
  parameters.chargeRate = chargeRate;

  return (batteryCheck(parameters));
}

float convertTempinFahrenite (float tempInCelsius)
{
  return ((tempInCelsius * (9/5)) + 32);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
