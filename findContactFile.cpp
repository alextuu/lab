#include <iostream>
#include "functions.hpp"
using namespace std;

int main()
{
  string filename;
  string searchName;
  cout << "Input the name of your contacts file: ";
  cin >> filename;
  cout << "Input a name you want to search: ";
  cin.ignore();
  getline(cin, searchName);
  int pos = findContactFile(filename, searchName);
  if(pos!=-1)
  {
  	cout << searchName << " was found in position " << pos << " of " << filename;
  }
  else
    cout << "The search name could not be found";
  return 0;
}
