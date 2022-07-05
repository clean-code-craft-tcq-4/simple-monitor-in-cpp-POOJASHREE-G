#ifndef STANDARD_BATTERY_SPECIFICATION_HPP
#define STANDARD_BATTERY_SPECIFICATION_HPP

class Charge_Temperature
{
  public:
  const float Lower_Threshold = 0.0F; // In Celcius
  const float Upper_Threshold = 45.0F; // In Celcius

};

class StateOfCharge
{
  public:
  const float Lower_Threshold = 20.0F; // In Percentage
  const float Upper_Threshold = 80.0F; // In Percentage
};

class ChargeRate
{
  public:
  const float Lower_Threshold = 0.0F;
  const float Upper_Threshold = 0.8F;
};

#endif