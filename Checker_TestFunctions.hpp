#ifndef CHECKER_TESTFUNCTIONS_HPP
#define CHECKER_TESTFUNCTIONS_HPP

template <typename temperature, class Charge_Discharge_SOC_Temp>
bool ChargeTemp_SOC_CRate_Check(temperature temp_SOC, Charge_Discharge_SOC_Temp ClsName);

template <typename temperature, typename soc, typename chargeRate>
bool batteryIsOk(temperature temp, soc State_Of_Charge, chargeRate CRate);

#endif