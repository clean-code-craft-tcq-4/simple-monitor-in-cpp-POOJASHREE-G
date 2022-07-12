#ifndef CHECKER_TESTFUNCTIONS_HPP
#define CHECKER_TESTFUNCTIONS_HPP

#include <iostream>
#include "Checker_TestFunctions.hpp"
#include "Standard_Battery_Specifications.hpp"
using namespace std;

const int Tolerance_percentage = 5;

inline bool ActionIsRequired(bool chargetemp, bool SOC, bool Charge_Rate){
    bool Check_m = (chargetemp && SOC && Charge_Rate);
    return Check_m;
}

template <class Threshold_Tolerance>
inline int Warning_Tolerance(Threshold_Tolerance Thres_tolerance_Cls) {
    float temp = ((Thres_tolerance_Cls.Upper_Threshold) * (Tolerance_percentage)) / 100;
    return (temp);
}

template <typename test_thres, class Charge_Discharge_SOC_Temp>
void IsItApproaching_LowerLimit(test_thres test_treshold, Charge_Discharge_SOC_Temp ClsName, float Warning_tolerance_range) {

    if(test_treshold <= (ClsName.Lower_Threshold + Warning_tolerance_range) && test_treshold >= ClsName.Lower_Threshold) {
        cout << "Warning: Approaching Lower Limit\n";
    }
}

template <typename test_thres, class Charge_Discharge_SOC_Temp>
void IsItApproaching_UpperLimit(test_thres test_treshold, Charge_Discharge_SOC_Temp ClsName, float Warning_tolerance_range) {

    if (test_treshold <= (ClsName.Upper_Threshold) && test_treshold >= (ClsName.Upper_Threshold  - Warning_tolerance_range))
    {
        cout << "Warning: Approaching Upper Limit\n";
    }
}


template <typename test_thres, class Charge_Discharge_SOC_Temp>
void Early_Warning(test_thres test_treshold, Charge_Discharge_SOC_Temp ClsName) {

    float Warning_tolerance_range = Warning_Tolerance(ClsName);

    IsItApproaching_LowerLimit(test_treshold, ClsName, Warning_tolerance_range);
    IsItApproaching_UpperLimit(test_treshold, ClsName, Warning_tolerance_range);

}


template <typename test_thres, class Charge_Discharge_SOC_Temp>
bool Threshold_Range_Check(test_thres test_treshold, Charge_Discharge_SOC_Temp ClsName) {

  Early_Warning(test_treshold, ClsName);

  if(test_treshold <= ClsName.Lower_Threshold || test_treshold >= ClsName.Upper_Threshold) {
    cout << "Charging Temperature/State Of Charge/Charge Rate out of range!\n";
    return false;
  }
  return true;
}

template <typename cls_far>
double IsItCelcs_FarnhCheck(cls_far cls_far_t, double value) {

    if(cls_far_t == FAHRENHEIT) {
        return ((value - 32) * 5 / 9);
    }
    return value;
}

template <typename temperature, typename temp_variation, typename soc, typename chargeRate>
bool batteryIsOk(temperature temper, temp_variation IsItCelcs_Farnh, soc State_Of_Charge, chargeRate CRate) {

  double temp = IsItCelcs_FarnhCheck(IsItCelcs_Farnh, temper);
  Charge_Temperature Charge_temp_obj;
  StateOfCharge Soc_temp_obj;
  ChargeRate CRate_temp_obj;

  bool chargetemp = Threshold_Range_Check<temperature, Charge_Temperature>(temp, Charge_temp_obj);
  bool SOC = Threshold_Range_Check<soc, StateOfCharge>(State_Of_Charge, Soc_temp_obj);
  bool Charge_Rate = Threshold_Range_Check<chargeRate, ChargeRate>(CRate, CRate_temp_obj);

  bool Combined_Check_b = ActionIsRequired(chargetemp, SOC, Charge_Rate);

  if((Combined_Check_b) == true){
    return true;
  }
  return false;
}

#endif