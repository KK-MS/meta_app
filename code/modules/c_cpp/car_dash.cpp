#include <iostream>
#include <fstream>
#include <map> // For map

// application include
#include "car_dash_meta.h"

using namespace std;

// Metainfo class
class CarDash
{
    string sMsg;
    CarDashMeta carMeta;

public:
    // default constructor
    CarDash()
    {
        sMsg = "";
        carMeta = CarDashMeta();
    }

    // constructor with filename
    CarDash(string sFilename)
    {
        CarDashMeta _cdm = CarDashMeta(sFilename);
        carMeta = _cdm;
    }

    // Getters
    string msg() { return sMsg; }
    string name() { return carMeta.getName(); }
    string version() { return carMeta.getVersion(); }
    string signName(int iSign) { return carMeta.getSignName(iSign); }
    void printMeta() {return carMeta.printMeta();}

    // Algorithms

    // Methods

    // configure
    int config()
    {
        cout << "CFG" << endl;
        carMeta = CarDashMeta("config.txt");
        return 1;
    }

    // link to server
    int link()
    {
        cout << "LINK" << endl;
        return 1;
    }

    // runtime processing
    int run()
    {
        cout << "RUN" << endl;
        return 1;
    }

    // stop the application
    int stop()
    {
        cout << "STOP" << endl;
        return 1;
    }

    // end the application and free the resources
    int end()
    {
        cout << "END" << endl;
        return 1;
    }
};

main()
{
    CarDash carDash;

    if (!carDash.config())
    {
        cout << carDash.msg();
        return -1;
    }

    // print the banner
    cout << "App: " << carDash.name() << endl;
    cout << "Ver: " << carDash.version() << endl;
    cout << "S Name: " << carDash.signName(1) << endl;
    carDash.printMeta();

    // link to server
    if (!carDash.link())
    {
        cout << carDash.msg();
        return -1;
    }

    // Run the application until stop event
    while (!carDash.stop())
    {
        carDash.run();
    }

    // end the application, free the resources
    carDash.end();
}