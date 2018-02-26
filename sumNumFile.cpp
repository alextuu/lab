// Describe your program
#include <iostream>
#include <fstream>
#include <istream>
#include <string> 
using namespace std;

// dont forget your function prototypes

int sumNumFiles (string fileName);

int main()
{
  string filename = "numbers.txt";
  int result =  sumNumFiles(filename); // replace 0 with a call to the sumNumFile function here.
  cout << "The sum of the values in " << filename << " is " << result <<"." << endl;
  
 
 
  return 0;
}

// provide function implementation here
int  sumNumFiles(string fileName){
  
  ifstream dataFile;
int num =0, totalNum = 0;
dataFile.open(fileName);
if(dataFile)
{
  while(dataFile >> num)
  {
    num+=num;
  }
}
else
{
  cout << "The file could not be loaded. Cannot perform operations on the file";
}

return num;
}
