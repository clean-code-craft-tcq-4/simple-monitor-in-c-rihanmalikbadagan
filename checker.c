#include <stdio.h>
#include <assert.h>
#include "batteryCheckStub.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {

  return (batteryCheck(temperature, 0, 45) && batteryCheck(soc, 20, 80) && batteryCheck(chargeRate, 0, 0.8));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
