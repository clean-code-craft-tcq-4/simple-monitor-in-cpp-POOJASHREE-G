#include <assert.h>
#include <iostream>
#include "Checker_TestFunctions.hpp"
using namespace std;

int main() {
  assert(batteryIsOk(25, CELSIUS, 70, 0.7) == true);
  assert(batteryIsOk(50, CELSIUS, 85, 0) == false);       // Temp, SOC out-of-range.
  assert(batteryIsOk(80, CELSIUS, 90, 1) == false);       // Temp, SOC, ROC out-of range.
  assert(batteryIsOk(25, CELSIUS, 79, 0.7) == true);      // SOC approaching upper limit.
  assert(batteryIsOk(25, CELSIUS, 21, 0.7) == true);      // SOC approaching lower limit.
  assert(batteryIsOk(77, FAHRENHEIT, 21, 0.7) == true);   // SOC approaching lower limit.
  assert(batteryIsOk(122, FAHRENHEIT, 70, 0.7) == false);  // Temp Out-of-range.
}
