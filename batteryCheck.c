#include <stdio.h>
#include "batteryCheck.h"
#include "messages.h"

int isApproachingLowerThreshold(float currentValue, float toleranceLimit)
{
    if (currentValue <= toleranceLimit)
    {
        return LOW_LIMIT;
    }

    return NORMAL_LIMIT;
}

int isApproachingHigherThreshold(float currentValue, float toleranceLimit)
{
    if (currentValue >= toleranceLimit)
    {
        return HIGH_LIMIT;
    }

    return NORMAL_LIMIT;
}

void checkTemperatureApproachingLimit(float currentTemp)
{
    if(isApproachingHigherThreshold(currentTemp, HIGH_TEMP_TOLERANCE_LIMIT))
    {
        printHighTempApproachWarning(EN);
    } 
    else if (isApproachingLowerThreshold(currentTemp, LOW_TEMP_TOLERANCE_LIMIT))
    {
        printLowTempApproachWarning(EN);
    }

}

void checkSocApproachingLimit(float currentSoc)
{
    if(isApproachingHigherThreshold(currentSoc, HIGH_SOC_TOLERANCE_LIMIT))
    {
        printHighSocApproachWarning(EN);
    } 
    else if (isApproachingLowerThreshold(currentSoc, LOW_SOC_TOLERANCE_LIMIT))
    {
        printLowSocApproachWarning(EN);
    }
}

void checkChargeRateApproachingLimit(float currentChargeRate)
{
    if(isApproachingHigherThreshold(currentChargeRate, HIGH_CR_TOLERANCE_LIMIT))
    {
        printHighCRApproachWarning(EN);
    } 
    else if (isApproachingLowerThreshold(currentChargeRate, LOW_CR_TOLERANCE_LIMIT))
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

int batteryCheck(struct BatteryParameters parameters)
{

    if ((checkParameters(parameters.temperature, TEMP_LOW_LIMIT, TEMP_HIGH_LIMIT) 
        && checkParameters(parameters.soc, SOC_LOW_LIMIT, SOC_HIGH_LIMIT) 
            && checkParameters (parameters.chargeRate, CR_LOW_LIMIT, CR_HIGH_LIMIT)) == NOT_OK)
    {
        return NOT_OK;
    } else
    {
        checkTemperatureApproachingLimit(parameters.temperature);
        checkSocApproachingLimit(parameters.soc);
        checkChargeRateApproachingLimit(parameters.chargeRate);
    }

    return IS_OK;
}