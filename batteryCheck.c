#include <stdio.h>
#include "batteryCheck.h"
#include "messages.h"

void isTempApproachingLowerThreshold(float currentValue)
{
    if (currentValue <= LOW_TEMP_TOLERANCE_LIMIT)
    {
        printLowTempApproachWarning(EN);
    }
}

void isTempApproachingHigherThreshold(float currentValue)
{
    if (currentValue >= HIGH_TEMP_TOLERANCE_LIMIT)
    {
        printHighTempApproachWarning(EN);
    }
}

void isSOCApproachingLowerThreshold(float currentValue)
{
    if (currentValue <= LOW_SOC_TOLERANCE_LIMIT)
    {
        printLowSocApproachWarning(EN);
    }
}

void isSOCApproachingHigherThreshold(float currentValue)
{
    if (currentValue >= HIGH_SOC_TOLERANCE_LIMIT)
    {
        printHighSocApproachWarning(EN);
    }
}

void isCRApproachingLowerThreshold(float currentValue)
{
    if (currentValue <= LOW_CR_TOLERANCE_LIMIT)
    {
        printLowCRApproachWarning(EN);
    }
}

void isCRApproachingHigherThreshold(float currentValue)
{
    if (currentValue >= HIGH_CR_TOLERANCE_LIMIT)
    {
        printHighCRApproachWarning(EN);
    }
}

int checkParameters (float currentValue, float minValue, float maxValue)
{
    if (currentValue <= minValue || currentValue >= maxValue)
    {
        return NOT_OK;
    }

    return IS_OK;
}

int batteryCheck(struct BatteryParameters parameters)
{
    if (checkParameters(parameters.temperature, TEMP_LOW_LIMIT, TEMP_HIGH_LIMIT) 
        && checkParameters(parameters.soc, SOC_LOW_LIMIT, SOC_HIGH_LIMIT) 
            && checkParameters (parameters.chargeRate, CR_LOW_LIMIT, CR_HIGH_LIMIT))
    {
        //isBatteryAttributesApproachingLimit(parameters);
        return IS_OK;
    }
    return NOT_OK;
}

void isBatteryAttributesApproachingLimit(struct BatteryParameters parameters)
{
    isTempApproachingLowerThreshold(parameters.temperature);
    isTempApproachingHigherThreshold(parameters.temperature);
    isSOCApproachingLowerThreshold(parameters.soc);
    isSOCApproachingHigherThreshold(parameters.soc);
    isCRApproachingLowerThreshold(parameters.chargeRate);
    isCRApproachingHigherThreshold(parameters.chargeRate);
}