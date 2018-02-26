
// Describe your program
#include <iostream>
#include <fstream>
using namespace std;
int main()
{


int arr1[2][4] = {{10, 25, 87, 6}, {99, 59, 44, 75}};




// variable declaration
  ofstream outputFile; // variable holding connection to an output file 
  outputFile.open("data2d.txt"); // opens the output file

  // write data to the output file
  outputFile  << "2 4" << endl;

for (int i=0; i<2; i++){
  for (int j=0; j<4; j++){
  outputFile << arr1[i][j]<< " "; }
  outputFile << endl;
  } 

 outputFile.close();
  return 0;
}
