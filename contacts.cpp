#include <iostream>
#include <fstream>
#include <string>
#include "functions.hpp"
using namespace std;

int main()
{
  string filename;
  cout << "What is the name of your contacts file? ";
  cin >> filename;
  loadContacts(filename);
  return 0;
}
