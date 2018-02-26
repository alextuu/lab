// Describe your program
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// dont forget your function prototype
int writeStringArray(string namesInFunc[]);

int main()
{
	string names[5] = {"Hugo", "Kate", "Masako", "Borimas", "Seo"};
	// call the writeArray method fo smoothing things out.
	writeStringArray(names);
	
	
	return 0;
}

int writeStringArray(string namesInFunc[])
{

// variable declaration
  ofstream outputFile; // variable holding connection to an output file 
  outputFile.open("warString.txt"); // opens the output file

  // write data to the output file
  outputFile  << "5" << endl;

for (int i=0; i<5; i++){
  outputFile << namesInFunc[i]<< " "; 
  outputFile << endl;
  } 





 outputFile.close();
  return 0;
}




