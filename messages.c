#include <stdio.h>
#include "messages.h"
#include "batteryCheck.h"

void printHighTempApproachWarning(int language)
{
    if (language == EN)
    {
        printf("[Warning] Temperature approaching higher limit\n");
    } else if (language == DE)
    {
        printf("[Warnung] Temperatur nähert sich der höheren Grenze\n");
    }
}

void printLowTempApproachWarning(int language)
{
    if (language == EN)
    {
        printf("[Warning] Temperature approaching Lower limit\n");
    } else if (language == DE)
    {
        printf("[Warnung] Temperatur nähert sich der unteren Grenze\n");
    }
}

void printHighSocApproachWarning(int language)
{
    if (language == EN)
    {
        printf("[Warning] SOC approaching higher limit\n");
    } else if (language == DE)
    {
        printf("[Warnung] SOC nähert sich der höheren Grenze\n");
    }
}

void printLowSocApproachWarning(int language)
{
    if (language == EN)
    {
        printf("[Warning] SOC approaching Lower limit\n");
    } else if (language == DE)
    {
        printf("[Warnung] SOC nähert sich der unteren Grenze\n");
    }
}

void printHighCRApproachWarning(int language)
{
    if (language == EN)
    {
        printf("[Warning] Charge Rate approaching higher limit\n");
    } else if (language == DE)
    {
        printf("[Warnung] Charge Rate nähert sich der höheren Grenze\n");
    }
}

void printLowCRApproachWarning(int language)
{
    if (language == EN)
    {
        printf("[Warning] Charge Rate approaching Lower limit\n");
    } else if (language == DE)
    {
        printf("[Warnung] Charge Rate nähert sich der unteren Grenze\n");
    }
}