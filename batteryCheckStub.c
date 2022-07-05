#include <stdio.h>
#include "batteryCheckStub.h"

int batteryCheck(float currentValue, float minValue, float maxValue)
{
    if (currentValue < minValue || currentValue > maxValue)
    {
        return NOT_OK;
    }

    return IS_OK;
}