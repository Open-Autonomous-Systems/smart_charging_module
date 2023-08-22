class OAS_SmartSwitch
{
public:
  OAS_SmartSwitch(){};
  ~OAS_SmartSwitch() = default;
  enum OASState {r2fly = 1, charging = 2, payload = 3};

  void setState(OASState state)
  {
    state_ = state;
      switch (state) {
          case OASState::r2fly:
              setR2FlyState();
              break;
          case OASState::charging:
              setChargingState();
              break;
          case OASState::payload:
              setPayloadState();
              break;
          default:
              Serial << "Input valid OASState\n";
      }
  }

  OASState getState()
  {
    return state_;
  }
  //
  void setWakeUpEpoch(uint32_t epoch)
  {
      // check of epoch >0 and > now()
    nextWakeUpEpoch_ = epoch;
    // adjust next rtc wakeup alarm interrupt to nextWakeUpEpoch_
  }

  uint32_t getWakeUpEpoch()
  {
    return nextWakeUpEpoch_;
  }

  void setRTC2Epoch(uint32_t& epoch)
  {
      // set rtc time to epoch
      if (epoch == 0)
          epoch = 1672549200; // Jan 1, 2023 00:00:00
      DateTime dt = DateTime(epoch);
      rtc_.adjust(epoch);
  }

  uint32_t getEpoch()
  {
    // get rtc time
    return rtc_.now().unixtime();
  }
  //
  uint32_t& getLastKnownEpoch()
  {
    static uint32_t lastKnownEpoch;
    EpochFlash.read(lastKnownEpoch);
    return lastKnownEpoch;
  }

  void saveEpoch2Flash()
  {
    // get current epoch from rtc
    uint32_t time_now = getEpoch();
    // save it flash
    EpochFlash.write(time_now);
  }
  //

  void setSessionId(uint8_t sessionId)
  {
    sessionId_ = sessionId;
    // save sessionId to flash
    sessionIdFlash.write(sessionId);
  }

  uint8_t getSessionId()
  {
    return sessionId_;
  }

  uint8_t getLastSessionId()
  {
    uint8_t LastSessionId;
    sessionIdFlash.read(LastSessionId);
    return LastSessionId;
  }

  void autoIncrementSessionId()
  {
      setSessionId(getLastSessionId() + 1);
  }

  void setVerbose()
  {
    verbose_ = true;
  }
  //
private:
  bool verbose_{false};
  uint8_t sessionId_;
  OASState state_;
  uint32_t nextWakeUpEpoch_;

  void setPayloadState()
  {
    // TURN OFF r2fly out
    bool retR2f = r2fSwitch_.setState(false);
    digitalWrite(PIN_LED_R2FLY, HIGH); // inverted logic
    // turn OFF pdb for ESCs.
    bool retESC = escSwitch_.setState(false);

    // turn ON payload rail
    bool retPayload = payloadSwitch_.setState(true);
      digitalWrite(PIN_LED_PAYLOAD, LOW); // inverted logic
      
      // turn ON solar charging
    bool retSolar = solarSwitch_.setState(true);

    diagnostics_.status = retR2f && retESC && retPayload && retSolar;
    if (diagnostics_.status)
      diagnostics_.state = OASState::payload;
    
    if (verbose_)
    {
      Serial <<"\nPayload State Engaged, status:\n";
      Serial <<"\tR2Fly Rail: "<<retR2f<<"\n";
      Serial <<"\tPayload Rail: "<<retPayload<<"\n";
      Serial <<"\tESC: "<< retESC<<"\n";
      Serial <<"\tCharging: "<<retSolar<<"\n";
    }
  }

  void setR2FlyState()
  {
    // Turn ON r2fly out 
    bool retR2f = r2fSwitch_.setState(true);
    digitalWrite(PIN_LED_R2FLY, LOW); // inverted logic
    // turn on pdb for ESCs.
    bool retESC = escSwitch_.setState(true);
    // turn on payload rail
    bool retPayload = payloadSwitch_.setState(true);
      digitalWrite(PIN_LED_PAYLOAD, LOW); // inverted logic
      // turn off solar charging
    bool retSolar = solarSwitch_.setState(false);

      if (verbose_)
      {
        Serial <<"\nReady2Fly State Engaged, status:\n";
        Serial <<"\tR2Fly Rail: "<<retR2f<<"\n";
        Serial <<"\tPayload Rail: "<<retPayload<<"\n";
        Serial <<"\tESC: "<< retESC<<"\n";
        Serial <<"\tCharging: "<<retSolar<<"\n";
      }
  }

  void setChargingState()
  {
    // TURN OFF r2fly out
    bool retR2f = r2fSwitch_.setState(false);
    digitalWrite(PIN_LED_R2FLY, HIGH); // inverted logic
    // turn OFF pdb for ESCs.
    bool retESC = escSwitch_.setState(false);
    // turn OFF payload rail
    bool retPayload = payloadSwitch_.setState(false);
      digitalWrite(PIN_LED_PAYLOAD, HIGH); // inverted logic
      
      // turn ON solar charging
    bool retSolar = solarSwitch_.setState(true);
      
      if (verbose_)
      {
        Serial <<"\nCharging State Engaged, status:\n";
        Serial <<"\tR2Fly Rail: "<<retR2f<<"\n";
        Serial <<"\tPayload Rail: "<<retPayload<<"\n";
        Serial <<"\tESC: "<< retESC<<"\n";
        Serial <<"\tCharging: "<<retSolar<<"\n";
      }
  }

  void updateDiagnostics()
  {
    diagnostics_.ESC = escSwitch_.getState();
    diagnostics_.r2flyRail = r2fSwitch_.getState();
    diagnostics_.payloadRail = payloadSwitch_.getState();
    diagnostics_.charging = solarSwitch_.getState();
    diagnostics_.upTime = getEpoch() - millis()/1e-3;
  }
};
