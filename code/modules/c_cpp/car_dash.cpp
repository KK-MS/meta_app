#include <iostream>
#include <fstream>
#include <map> // For map

// application include
#include "car_dash_meta.h"

using namespace std;

string gCarBanner = "\
  #####                   ######                       \n\
 #     #   ##   #####     #     #   ##    ####  #    # \n\
 #        #  #  #    #    #     #  #  #  #      #    # \n\
 #       #    # #    #    #     # #    #  ####  ###### \n\
 #       ###### #####     #     # ######      # #    # \n\
 #     # #    # #   #     #     # #    # #    # #    # \n\
  #####  #    # #    #    ######  #    #  ####  #    # \n\
";

// Metainfo class
class CarDash
{
    string sMsg;
    CarDashMeta carMeta;
    enum logLevels
    {
        ERR,
        WARN,
        INFO,
        DBG
    };
    logLevels ll;

    // Private methods
    int print(logLevels level, string str)
    {
        int status = 0;

        if (level <= ll)
        {
            cout << str << endl;
            status = 1;
        }
        return status;
    }

public:
    // default constructor
    CarDash()
    {
        sMsg = "";
        carMeta = CarDashMeta();
        ll = INFO;
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
    void printMeta() { return carMeta.printMeta(); }

    // Setters
    void setLogDgb() { ll = DBG; }
    void setLogInfo() { ll = INFO; }
    void setLogWarn() { ll = WARN; }
    void setLogErr() { ll = ERR; }

    // Algorithms

    // Methods
    void banner()
    {
        print(INFO, gCarBanner);
    }

    // configure
    int config()
    {
        print(DBG, "CFG");
        carMeta = CarDashMeta("config.txt");
        return 1;
    }

    // end the application and free the resources
    int end()
    {
        print(DBG, "END");
        return 1;
    }

    // link to server
    int link()
    {
        print(DBG, "LINK");
        return 1;
    }

    // runtime processing
    int run()
    {
        print(DBG, "RUN");
        return 1;
    }

    // stop the application
    int stop()
    {
        print(DBG, "STOP");
        return 1;
    }

};

main()
{
    CarDash carDash;

    // display banner
    carDash.banner();

    if (!carDash.config())
    {
        cout << carDash.msg();
        return -1;
    }

    // print the banner
    cout << "App: " << carDash.name() << endl;
    cout << "Ver: " << carDash.version() << endl;
    cout << "S Name: " << carDash.signName(1) << endl;

    // enable info level print
    carDash.setLogInfo();

    // if debug level is enabled, print meta information
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