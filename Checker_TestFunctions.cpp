#include <iostream>
#include "Checker_TestFunctions.hpp"
#include "Standard_Battery_Specifications.hpp"
using namespace std;

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
  if(!chargetemp){
    cout << "Warning: Charging Temperature out of range!\n";
  }
  bool SOC = ChargeTemp_SOC_CRate_Check<soc, StateOfCharge>(State_Of_Charge, Soc_temp_obj);
  if(!SOC){
    cout << "Warning: State Of Charge out of range!\n";
  }
  bool Charge_Rate = ChargeTemp_SOC_CRate_Check<chargeRate, ChargeRate>(CRate, CRate_temp_obj);
  if(!Charge_Rate){
    cout << "Warning: Charge Rate out of range!\n";
  }

  if((chargetemp && SOC && Charge_Rate) == true){
    return true;
  }
  return false;
}