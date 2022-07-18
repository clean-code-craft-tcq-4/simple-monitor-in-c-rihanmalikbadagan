#include <stdio.h>
#include "batteryCheck.h"
#include "messages.h"


void checkTemperatureApproachingLimit(float currentTemp, float tempToleranceLimit)
{
    if(isApproachingHigherThreshold(currentTemp, tempToleranceLimit))
    {
        printHighTempApproachWarning(EN);
    } else if (isApproachingLowerThreshold(currentTemp, tempToleranceLimit))
    {
        printLowTempApproachWarning(EN);
    }

}

void checkSocApproachingLimit(float currentSoc, float socToleranceLimit)
{
    if(isApproachingHigherThreshold(currentSoc, socToleranceLimit))
    {
        printHighSocApproachWarning(EN);
    } else if (isApproachingLowerThreshold(currentSoc, socToleranceLimit))
    {
        printLowSocApproachWarning(EN);
    }
}

void checkChargeRateApproachingLimit(float currentChargeRate, float chargeRateToleranceLimit)
{
    if(isApproachingHigherThreshold(currentChargeRate, chargeRateToleranceLimit))
    {
        printHighCRApproachWarning(EN);
    } else if (isApproachingLowerThreshold(currentChargeRate, chargeRateToleranceLimit))
    {
        printLowCRApproachWarning(EN);
    }
}

int checkParameters (float currentValue, float minValue, float maxValue)
{
    if (currentValue < minValue || currentValue > maxValue)
    {
        return NOT_OK;
    }

    return IS_OK;
}

int isApproachingLowerThreshold(float currentValue, float minValue, float maxValue)
{
    if (currentValue < (minValue + TOLERENCE_LIMIT(maxValue)))
    {
        return LOW_LIMIT;
    }

    return NORMAL_LIMIT;
}

int isApproachingHigherThreshold(float currentValue, float minValue, float maxValue)
{
    if (currentValue > (maxValue - TOLERANCE_LIMIT(maxValue)))
    {
        return HIGH_LIMIT;
    }

    return NORMAL_LIMIT;
}

int batteryCheck(BatteryParameters parameters)
{

    if ((checkParameters(parameters.temperature, TEMP_LOW_LIMIT, TEMP_HIGH_LIMIT) 
        && checkParameters(parameters.soc, SOC_LOW_LIMIT, SOC_HIGH_LIMIT) 
            && checkParameters (parameters.chargeRate, CR_LOW_LIMIT, CR_HIGH_LIMIT)) == NOT_OK)
    {
        return NOT_OK;
    } else
    {
        checkTemperatureApproachingLimit(parameters.temperature, TEMP_TOLERANCE_LIMIT);
        checkSocApproachingLimit(parameters.soc, SOC_TOLERANCE_LIMIT);
        checkChargeRateApproachingLimit(parameters.chargeRate, CR_TOLERANCE_LIMIT);
    }

    return IS_OK;
}