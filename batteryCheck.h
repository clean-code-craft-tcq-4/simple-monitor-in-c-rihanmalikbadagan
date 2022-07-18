#define IS_OK 1
#define NOT_OK 0 

#define TEMP_HIGH_LIMIT 45
#define TEMP_LOW_LIMIT 0

#define SOC_HIGH_LIMIT 80
#define SOC_LOW_LIMIT 20

#define CR_HIGH_LIMIT 0.8
#define CR_LOW_LIMIT 0

#define TOLERANCE_LIMIT(X) (X * 0.05)

#define TEMP_TOLERANCE_LIMIT TOLERANCE_LIMIT(TEMP_HIGH_LIMIT)
#define SOC_TOLERANCE_LIMIT TOLERANCE_LIMIT(SOC_HIGH_LIMIT)
#define CR_TOLERANCE_LIMIT TOLERANCE_LIMIT(CR_HIGH_LIMIT)

enum Status {NORMAL_LIMIT = 0, HIGH_LIMIT = 1, LOW_LIMIT = 2};

enum Language {EN = 0, DE = 1};

struct BatteryParameters
{
  float temperature;
  float soc;
  float chargeRate;
};

int 
batteryCheck(float currentValue, float minValue, float maxValue);