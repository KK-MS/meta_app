// basic file operations
#include <iostream>
#include <fstream>
#include <map> // For map

// application include
#include "metainfo.h"

using namespace std;

// Main application
int main()
{
  Metainfo meta("config.txt");
  cout << "Print full map" << endl;
  meta.printMap();
  cout << "Access key element 'App.Version' = " << meta.getValue("App.Version");
  return 0;
}
