#include "RTC_SAMD51.h"
RTC_SAMD51 rtc_;
///////////////////////////
extern "C" char *sbrk(int i);
int GetFreeRam () {
char stack_dummy = 0;
return &stack_dummy - sbrk(0);
}
/////////////////////////////////////////
template <typename T>
Print& operator<<(Print& printer, T value)
{
    printer.print(value);
    return printer;
}
/////////////////////////////////////////
#define BATTERY_TOTAL_CAP 25.2

struct OAS_battery
{
	volatile float voltage = 0.0;
	volatile float percentage = 0.0;
	volatile float current = 0.0;
};
static OAS_battery batteryModule;

float getVoltage()
{
  //static float voltageCell[5];
  //static float voltageCell = (analogRead(PIN_VOLTAGE_CELL0) * 3.3)/4096.0;
  analogReadResolution(12);
  analogReadCorrection(8, 2053);
  return (analogRead(PIN_VOLTAGE_CELL0) * 3.3)/4096.0;
}

float getCurrent()
{
  float count=150.0;
  float Samples=0.0,AvgAcs=0.0;
  volatile float AcsValueF=0.0;
  analogReadResolution(12);
  analogReadCorrection(8, 2053);
  for (int x = 0; x < count; x++)
  { //Get 150 samples
    
    Samples = Samples + analogRead(PIN_CURRENT_SENS);  //Add samples together
    delay(3); // let ADC settle before next sample 3ms
  }
  AvgAcs=Samples/count;//Taking Average of Samples
  AcsValueF = ((AvgAcs * (3.3 / 4096.0))/(100.0 * 250e-6));
  //float sum_current = map(AcsValueF, 0, 132, 0, 255);
  Serial << "new current " << (AvgAcs * (3.3 / 4096.0))a <<"\n";
  return(AcsValueF);
}

void getBatteryInfo(OAS_battery& battery)
{
  /*
  float* batteryValue;
  batteryValue = getVoltage();
  for (int i=0; i<6; i++)
  {
    totalVoltage += batteryValue[i];
  }
  */
  battery.voltage = getVoltage();
  battery.percentage = battery.voltage / BATTERY_TOTAL_CAP;
  battery.current = getCurrent();
}
/////////////////////////////////////////
struct OAS_diagnostics
{
	int state;
	bool status;
	bool ESC;
	bool charging;
	bool r2flyRail;
	bool payloadRail;
	uint32_t upTime;
};
OAS_diagnostics diagnostics_;
/////////////////////////////////////////
