#ifndef CHECKER_TESTFUNCTIONS_HPP
#define CHECKER_TESTFUNCTIONS_HPP

#include <iostream>
#include "Checker_TestFunctions.hpp"
#include "Standard_Battery_Specifications.hpp"
using namespace std;


inline bool Combined_Check(bool chargetemp, bool SOC, bool Charge_Rate){
    bool Check_m = (chargetemp && SOC && Charge_Rate);
    return Check_m;
}

template <typename temperature, class Charge_Discharge_SOC_Temp>
bool ChargeTemp_SOC_CRate_Check(temperature temp_SOC, Charge_Discharge_SOC_Temp ClsName) {

  if(temp_SOC <= ClsName.Lower_Threshold || temp_SOC >= ClsName.Upper_Threshold) {
    cout << "Charging Temperature/State Of Charge/Charge Rate out of range!\n";
    return false;
  }
  return true;
}


template <typename temperature, typename soc, typename chargeRate>
bool batteryIsOk(temperature temp, soc State_Of_Charge, chargeRate CRate) {

  Charge_Temperature Charge_temp_obj;
  StateOfCharge Soc_temp_obj;
  ChargeRate CRate_temp_obj;

  bool chargetemp = ChargeTemp_SOC_CRate_Check<temperature, Charge_Temperature>(temp, Charge_temp_obj);
  bool SOC = ChargeTemp_SOC_CRate_Check<soc, StateOfCharge>(State_Of_Charge, Soc_temp_obj);
  bool Charge_Rate = ChargeTemp_SOC_CRate_Check<chargeRate, ChargeRate>(CRate, CRate_temp_obj);

  bool Combined_Check_b = Combined_Check(chargetemp, SOC, Charge_Rate)

  if((Combined_Check_b) == true){
    return true;
  }
  return false;
}


#endif