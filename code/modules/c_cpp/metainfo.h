#include <iostream>
#include <fstream>
#include <map> // For map
using namespace std;

// Util function to trim end white spaces
inline std::string trim(std::string &str)
{
  str.erase(0, str.find_first_not_of(' ')); //prefixing spaces
  str.erase(str.find_last_not_of(' ') + 1); //surfixing spaces
  return str;
}

// Metainfo class
class Metainfo
{
  // metafile
  string sFilename;
  // complete metadata
  string sData;
  // latest execution status message
  string sMsg;
  // key value lookup map
  std::map<string, string> lookup;

  // methods internal to class

  // store the line into lookup map
  void mapLine(string sLine, int iLineNum)
  {
    string _sLine = trim(sLine);
    unsigned int _p = _sLine.find("=");
    string _k = "line:" + to_string(iLineNum);
    string _v = _sLine;
    char _ch = _sLine.at(0);

    // check if the line is a comment
    if (_ch != ';')
    {
      _k = sLine.substr(0, _p);
      _v = sLine.substr(_p + 1);
    }

    // remove whitespaces 
    _k = trim(_k);
    _v = trim(_v);
    lookup.insert(std::pair<string, string>(_k, _v));
  }


public:
  // Constructor with metafile
  Metainfo(string sFilename)
  {
    ifstream hFile(sFilename);
    if (!hFile.is_open())
    {
      sMsg = "Error: File not found: " + sFilename;
      cout << sMsg;
      return;
    }

    int iLineNum = 0;
    string sLine;

    // store the data and parallel map data.
    while (!hFile.eof())
    {
      getline(hFile, sLine);
      sData += sLine + "\n";

      iLineNum++;
      mapLine(sLine, iLineNum);
    }
    hFile.close();
  }
  // return the key mapped value
  string getValue(string key)
  {
    string v = lookup[key];
    return lookup[key];
  }

  // print the map table
  void printMap()
  {
    for (std::map<string, string>::iterator iter = lookup.begin(); iter != lookup.end(); ++iter)
    {
      string _k = iter->first;
      string _v = iter->second;
      cout << _k << "=" << _v << endl;
    }
  }
};
