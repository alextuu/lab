#include <iostream>
#include <istream>
#include <fstream>
using namespace std;

// dont forget your function prototype
int showNums(string filename);

int main()
{
	cout << "File contents: " <<endl;
	
	// call the showNums function
	showNums("numbers.txt");
	
	return 0;
}

int showNums(string filename){

ifstream dataFile;
int num;
dataFile.open(filename);
if(dataFile)
{
  while(dataFile >> num)
  {
    cout << num << endl;
  }
}
else
{
  cout << "The file could not be loaded. Cannot perform operations on the file";
}


}

