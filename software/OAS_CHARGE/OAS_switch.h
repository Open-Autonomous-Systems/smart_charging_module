class OAS_SWITCH
{
  public:
    OAS_SWITCH(int pinId, bool invertPinLogic):  pinId_(pinId), invertPinLogic_(invertPinLogic){};
    ~OAS_SWITCH() = default;
    
    bool setState(bool stateFlag)
    {
      if (stateFlag)
        switchON();
      else
        switchOFF();
      // feedback of state of switch after switching action
      return (stateFlag == getState());
    }

    bool getState()
    {
      return readPinState();
    }

  private:
    void switchON()
    {
      if (!invertPinLogic_)
        digitalWrite(pinId_, HIGH);
      else
        digitalWrite(pinId_, LOW);
    }

    void switchOFF()
    {
      if (!invertPinLogic_)
        digitalWrite(pinId_, LOW);
      else
        digitalWrite(pinId_, HIGH);
    }

    bool readPinState()
    { 
      if (!invertPinLogic_)
        return digitalRead(pinId_);
      else
        return !digitalRead(pinId_);
    }

    int pinId_;
    bool invertPinLogic_{false};
};
