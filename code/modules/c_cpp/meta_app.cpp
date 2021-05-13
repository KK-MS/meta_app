// basic file operations
#include <iostream>
#include <fstream>
#include <map> // For map

// application include
#include "car_dash_meta.h"

using namespace std;

// Main application
int main()
{
  CarDashMeta carDM("config.txt");
  cout << "Print full map" << endl;
  carDM.printMeta();
  cout << "App Name: " << carDM.getName() << endl;
  cout << "Sign 0 Name: " << carDM.getSignName(0) << endl;
  cout << "Sign 0, Status 1 Name: " << carDM.getStatusName(0,1) << endl;
  return 0;
}
