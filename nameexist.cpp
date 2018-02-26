#include <iostream>
#include "functions.hpp"
using namespace std;

int main()
{
  string searchName;
  string nameList[4] = {"Pei", "Samantha", "Pietro", "Kiran"};
  cout << "Input a name you want to search: ";
  cin >> searchName;
  bool found = nameExists(nameList, 4, searchName);
  if(found)
    cout << "Found ";
  else
    cout << "Could not find ";
  cout << searchName << " in the list of names [";
  for(int i = 0; i < 4; i++)
  {
    cout << nameList[i] << " ";
  }
  cout << "]";
  cout << findName(nameList, 4, searchName);
  return 0;
}
