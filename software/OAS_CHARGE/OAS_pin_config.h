
// ANALOG INPUT
#ifndef  PIN_CURRENT_SENS
  #define  PIN_CURRENT_SENS A0
#endif

#ifndef  PIN_VOLTAGE_CELL0
  #define  PIN_VOLTAGE_CELL0 A1
#endif

//LED

#ifndef PIN_LED_PAYLOAD
  #define PIN_LED_PAYLOAD 13
#endif

#ifndef PIN_LED_R2FLY
  #define PIN_LED_R2FLY 4
#endif

//Port
#ifndef  PIN_TX_OBC
  #define  PIN_TX_OBC TX
#endif

#ifndef  PIN_RX_OBC
  #define  PIN_RX_OBC RX
#endif
// Status or DigitalRead
#ifndef  PIN_SOLAR_S1
  #define  PIN_SOLAR_S1 11
#endif

#ifndef  PIN_SOLAR_S2
  #define  PIN_SOLAR_S2 12
#endif

// SWITCHES

#ifndef PIN_SOLAR
  #define PIN_SOLAR 10
#endif

#ifndef PIN_R2FLY_RAIL
  #define PIN_R2FLY_RAIL   9
#endif

#ifndef PIN_PAYLOAD_RAIL
  #define PIN_PAYLOAD_RAIL 6
#endif

#ifndef PIN_ESC
  #define PIN_ESC 5
#endif

void pinSetup()
{
  pinMode(PIN_ESC, OUTPUT);
  pinMode(PIN_SOLAR, OUTPUT);
  pinMode(PIN_PAYLOAD_RAIL, OUTPUT);
  pinMode(PIN_R2FLY_RAIL, OUTPUT);
  
  pinMode(PIN_LED_R2FLY, OUTPUT);
  pinMode(PIN_LED_PAYLOAD, OUTPUT);

  pinMode(PIN_SOLAR_S1, INPUT);
  pinMode(PIN_SOLAR_S2, INPUT);

  pinMode(PIN_CURRENT_SENS, INPUT);
  pinMode(PIN_VOLTAGE_CELL0, INPUT);
}