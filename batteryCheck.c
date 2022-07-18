#include <stdio.h>
#include "batteryCheck.h"
#include "messages.h"

int isTempApproachingLowerThreshold(float currentValue)
{
    if (currentValue <= LOW_TEMP_TOLERANCE_LIMIT)
    {
        printLowTempApproachWarning(EN);
        //return LOW_LIMIT;
    }

    return NORMAL_LIMIT;
}

int isTempApproachingHigherThreshold(float currentValue)
{
    if (currentValue >= HIGH_TEMP_TOLERANCE_LIMIT)
    {
        printHighTempApproachWarning(EN);
        //return HIGH_LIMIT;
    }

    return NORMAL_LIMIT;
}

int isSOCApproachingLowerThreshold(float currentValue)
{
    if (currentValue <= LOW_SOC_TOLERANCE_LIMIT)
    {
        printLowSocApproachWarning(EN);
        //return LOW_LIMIT;
    }

    return NORMAL_LIMIT;
}

int isSOCApproachingHigherThreshold(float currentValue)
{
    if (currentValue >= HIGH_SOC_TOLERANCE_LIMIT)
    {
        printHighSocApproachWarning(EN);
        //return HIGH_LIMIT;
    }

    return NORMAL_LIMIT;
}
int isCRApproachingLowerThreshold(float currentValue)
{
    if (currentValue <= LOW_CR_TOLERANCE_LIMIT)
    {
        printLowCRApproachWarning(EN);
        //return LOW_LIMIT;
    }

    return NORMAL_LIMIT;
}

int isCRApproachingHigherThreshold(float currentValue)
{
    if (currentValue >= HIGH_CR_TOLERANCE_LIMIT)
    {
        printHighCRApproachWarning(EN);
        //return HIGH_LIMIT;
    }

    return NORMAL_LIMIT;
}

/*void checkTemperatureApproachingLimit(float currentTemp)
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
}*/

int checkParameters (float currentValue, float minValue, float maxValue)
{
    printf("\n %f ## %f ## %f\n",currentValue,minValue,maxValue);
    if (currentValue <= minValue || currentValue >= maxValue)
    {
        return NOT_OK;
    }

    return IS_OK;
}

int batteryCheck(struct BatteryParameters parameters)
{
    printf("\n %f -- %f -- %f\n",parameters.temperature,parameters.soc,parameters.chargeRate);
    printf("\n %f --- %f --- %f\n",checkParameters(parameters.temperature, TEMP_LOW_LIMIT, TEMP_HIGH_LIMIT),checkParameters(parameters.soc, SOC_LOW_LIMIT, SOC_HIGH_LIMIT),checkParameters (parameters.chargeRate, CR_LOW_LIMIT, CR_HIGH_LIMIT));
    if ((checkParameters(parameters.temperature, TEMP_LOW_LIMIT, TEMP_HIGH_LIMIT) 
        || checkParameters(parameters.soc, SOC_LOW_LIMIT, SOC_HIGH_LIMIT) 
            || checkParameters (parameters.chargeRate, CR_LOW_LIMIT, CR_HIGH_LIMIT)))
    {
        return NOT_OK;
    }
    
    return IS_OK;
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