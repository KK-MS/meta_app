// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int main () {

  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();

  // Reading
  fstream myfileread;
  string data;
  myfileread.open ("example.txt", ios::in);
  myfileread >> data;
  myfileread.close();

  cout << endl;
  cout << data;

  return 0;
}
