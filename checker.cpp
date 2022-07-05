#include <assert.h>
#include <iostream>
#include "Checker_TestFunctions.hpp"
using namespace std;

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
