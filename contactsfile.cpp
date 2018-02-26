// Describe your program
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int writeArray(string array[], int size, string filename);

int main(){

int numNames = 0;

cout << "How many names will be stored in the address book? ";
cin >> numNames;
cin.ignore();

string arrNames[numNames];

  
for (int i=0; i < numNames; i++)
{
cout << "Name "<< i+1 << ": ";

getline(cin, arrNames[i]);

}
cout << "What filename do you want to use for the address book? "; 
string filename;
getline(cin, filename);


writeArray(arrNames, numNames, filename);
	
 
  return 0;
}



int writeArray(string array[], int size, string fileName){

  ofstream outputFile; // variable holding connection to an output file 
  outputFile.open(fileName); // opens the output file

    
 outputFile << size << endl;

for (int index = 0; index < size; index++)
 outputFile << array[index] << " " << endl;
 

 outputFile.close();
 
return 0;
}


