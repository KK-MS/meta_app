#include <iostream>
#include <fstream>
#include <map> // For map

// application include
#include "meta_info.h"

using namespace std;

// Metainfo class
class CarDashMeta
{
    MetaInfo meta;

    // private methods ---------------

    // get metavalue
    string getMetaValue(string key)
    {
        return meta.getValue(key);
    }

    // get sign key
    string signVal(int iSignIdx, string sField)
    {
        string _k = "Sign." + to_string(iSignIdx) + "." + sField;
        return getMetaValue(_k);
    }

    // get sign and status key
    string stsVal(int iSignIdx, int iStatusIdx, string sField)
    {
        string _k = "Sign." + to_string(iSignIdx) + ".Sts." + to_string(iStatusIdx) + "." + sField;
        return getMetaValue(_k);
    }

    // get app value
    string getAppVal(string field)
    {
        string _k = "App." + field;
        return getMetaValue(_k);
    }

public:
    // constructor
    CarDashMeta(string sFilename)
    {
        MetaInfo _m = MetaInfo(sFilename);
        meta = _m;
    }

    // print meta
    void printMeta()
    {
        meta.printMap();
    }

    // Getters
    string getName() { return getAppVal("Name"); }
    string getVersion() { return getAppVal("Version"); }
    string getInVideo() { return getAppVal("IN.Video"); }
    string getOutFile() { return getAppVal("Out.File"); }
    string getSignName(int iSign) { return signVal(iSign, "Name"); }
    string getStatusName(int iSign, int iSts) { return stsVal(iSign, iSts, "Name"); }
};