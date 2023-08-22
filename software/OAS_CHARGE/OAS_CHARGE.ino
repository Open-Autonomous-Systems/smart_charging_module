
#if !( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD51__) || defined(__SAMD51J20A__) \
      || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) || defined(__SAMD51P19A__)  \
      || defined(__SAMD21E15A__) || defined(__SAMD21E16A__) || defined(__SAMD21E17A__) || defined(__SAMD21E18A__) \
      || defined(__SAMD21G15A__) || defined(__SAMD21G16A__) || defined(__SAMD21G17A__) || defined(__SAMD21G18A__) \
      || defined(__SAMD21J15A__) || defined(__SAMD21J16A__) || defined(__SAMD21J17A__) || defined(__SAMD21J18A__) )
  #error This code is designed to run on SAMD21/SAMD51 platform! Please check your Tools->Board setting.
#endif
/////////////////////////////////////////////////////////////////
// These define's must be placed at the beginning before #include "SAMDTimerInterrupt.h"
// _TIMERINTERRUPT_LOGLEVEL_ from 0 to 4
// Don't define _TIMERINTERRUPT_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
// Don't define TIMER_INTERRUPT_DEBUG > 2. Only for special ISR debugging only. Can hang the system.
#define TIMER_INTERRUPT_DEBUG         0
#define _TIMERINTERRUPT_LOGLEVEL_     0
#include "SAMDTimerInterrupt.h"
#include "SAMD_ISR_Timer.h"
// TC3, TC4, TC5 max permissible HW_TIMER_INTERVAL_MS is 1398.101 ms, larger will overflow, therefore not permitted
// Use TCC, TCC1, TCC2 for longer HW_TIMER_INTERVAL_MS
#define HW_TIMER_INTERVAL_MS      10

#define SELECTED_TIMER      TIMER_TC3
// Init selected SAMD timer
SAMDTimer ITimer(SELECTED_TIMER);
////////////////////////////////////////////////
// Init SAMD_ISR_Timer
// Each SAMD_ISR_Timer can service 16 different ISR-based timers
SAMD_ISR_Timer ISR_Timer;
#define TIMER_INTERVAL_1S             1000L
#define TIMER_INTERVAL_2S             120000L
void TimerHandler(void)
{
  ISR_Timer.run();
}
/////////////////////////////////////////////////////////////////
#include "FlashStorage_SAMD.h" // for accessing internal flash
FlashStorage(EpochFlash, uint32_t);
FlashStorage(sessionIdFlash, uint8_t);
////////////////////////////////////////////////////////////////
#include "SAMD_AnalogCorrection.h"
#include "OAS_pin_config.h"
#include "OAS_utils.h"
////////////////////////////////////////////////////////////////
#include "OAS_switch.h"
OAS_SWITCH escSwitch_(PIN_ESC,true);
OAS_SWITCH r2fSwitch_(PIN_R2FLY_RAIL,false);
OAS_SWITCH payloadSwitch_(PIN_PAYLOAD_RAIL, true);
OAS_SWITCH solarSwitch_(PIN_SOLAR, false);
////////////////////////////////////////////////
#include "OAS_state.h"
OAS_SmartSwitch ss_;
/////////////////////////////////////////////////////////////////
// In SAMD, avoid doing something fancy in ISR, for example complex Serial.print with String() argument
// The pure simple Serial.prints here are just for demonstration and testing. Must be eliminate in working environment
// Or you can get this run-time error / crash
void firstTimerHandler()
{
  getBatteryInfo(batteryModule);
  Serial.println(F("payload "));
  Serial << "\n Current: "<< batteryModule.current<< " Voltage: "<< batteryModule.voltage<< " Percentage: "<< batteryModule.percentage<<"\n";
  /*bool r2flyState = ! r2fSwitch_.getState();
  if (!r2flyState)
  {
    Serial.println(F("on ground in payload only: "));
    ss_.setState(OAS_SmartSwitch::OASState::payload);
  }
  */
}

void secondTimerHandler()
{
  bool r2flyState = ! r2fSwitch_.getState();
  /*if (r2flyState)
  {
    Serial.println(F("Ready2Fly state init : "));
    ss_.setState(OAS_SmartSwitch::OASState::r2fly);
  }
  */
}

void setup()
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);
  delay(100);
  Serial1.begin(9600);
  while (!Serial1 && millis() < 5000);
  delay(100);
  Serial.print(F("\nStarting OAS Smart Switching Board")); 
  Serial.println(BOARD_NAME);
  analogReadResolution(12);
  analogReadCorrection(8, 2053);
  // configure pin in output mode
  pinSetup();
  // setup init 
  rtc_.begin(); // initialize RTC
  // set time to last known epoch
  ss_.setRTC2Epoch(ss_.getLastKnownEpoch());
  // set sessionId for run and save it to flash
  uint8_t sessionId = ss_.getLastSessionId() + 1;
  ss_.setSessionId(sessionId);
  // set state to r2f by default on bootup
  ss_.setState(OAS_SmartSwitch::OASState::r2fly);
  // Interval in milliSecs
  if (ITimer.attachInterruptInterval_MS(HW_TIMER_INTERVAL_MS, TimerHandler))
  {
    Serial.print(F("Starting ITimer OK, millis() = ")); Serial.println(millis());
  }
  else
    Serial.println(F("Can't set ITimer. Select another freq. or timer"));

  // Just to demonstrate, don't use too many ISR Timers if not absolutely necessary
  // You can use up to 16 timer for each ISR_Timer
  ISR_Timer.setInterval(TIMER_INTERVAL_1S,  firstTimerHandler);
  ISR_Timer.setInterval(TIMER_INTERVAL_2S,  secondTimerHandler);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
