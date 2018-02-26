/*
MIT License

Copyright (c) 2018 Paul Salvador Inventado

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "catch.hpp"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

string couttest(string progName, string input)
{
  FILE *fp = popen(("echo \""+ input +"\" | ./" + progName).c_str(), "r");
  char buf[1024];
  string output = "";
  while (fgets(buf, 1024, fp)) {
    output += buf;
  }
  pclose(fp);  
  return output;
}

string to_string_double(double val, const int prec = 2)
{
    std::ostringstream out;
    out << fixed << setprecision(prec) << val;
    return out.str();
}

string nameList[10] = {"John Lennon", "Paul McCartney", "George Harrison", "Ringo Starr", "Diana Ross", "Mary Wilson", "Florence Ballard", "Cindy Birdsong", "Jean Terrell", "Susaye Greene"};

TEST_CASE("Getting names from the command line", "[getnames]")
{
  SECTION("Check user input")
  {
      int randContacts = rand() % 10 + 1;      

      string expected = "How many names will be stored in the address book? ";
      string names = "";
      for(int i = 0; i < randContacts; i++)
      {
        expected+= "Name " + to_string(i+1) + ": ";
        names += nameList[i] + "\n";
      }
      string output = couttest("getnames", to_string(randContacts) + " " + names);
      CHECK(output == expected);
  }
}

TEST_CASE("Writing string arrays to files", "[warString]")
{
  SECTION("Check file creation")
  {    
    ifstream inputFile("names.txt");
    if(inputFile){
      inputFile.close();
      remove("names.txt");
    }
    system("./warString");
    inputFile.open("names.txt");
    CHECK(inputFile.good() == true);
    if(inputFile){
      int numContacts;
      inputFile >> numContacts;
      inputFile.ignore();
      CHECK(numContacts == 5);
      string names[5] = {"Hugo", "Kate", "Masako", "Borimas", "Seo"};
      for(int i = 0; i < 5; i++)
      {
        string name;
        inputFile >> name;
        CHECK(name == names[i]);
      }
      inputFile.ignore();
      inputFile.ignore();
      CHECK(inputFile.eof() == true);
      inputFile.close();
      //remove("names.txt");
    }
  }
}

TEST_CASE("Contacts file", "[contactsfile]")
{  
  srand (time(NULL));
  SECTION("Contacts input")
  {
    for(int i = 0; i < 10; i ++)
    {
      int randContacts = rand() % 10 + 1;      

      string expected = "How many names will be stored in the address book? ";
      string names = "";
      for(int i = 0; i < randContacts; i++)
      {
        expected+= "Name " + to_string(i+1) + ": ";
        names += nameList[i] + "\n";
      }
      expected += "What filename do you want to use for the address book? ";

      ifstream inputFile("contacts.txt");
      if(inputFile){
        inputFile.close();
        remove("contacts.txt");
      }
      string output = couttest("contactsfile", to_string(randContacts) + "\n" + names + "contacts.txt");
    
      inputFile.open("contacts.txt");
      CHECK(inputFile.good() == true);
      if(inputFile){
        int numContacts;
        inputFile >> numContacts;
        inputFile.ignore();
        CHECK(numContacts == randContacts);
        for(int i = 0; i < randContacts; i++)
        {
          string name;
          getline(inputFile, name);
          CHECK(name == nameList[i]);
        }
        inputFile.ignore();
        CHECK(inputFile.eof() == true);
        inputFile.close();
        remove("contacts.txt");
      }
    }
  }
}

TEST_CASE("Display file contents", "[showNums]")
{
  SECTION("Display file contents")
  {
    for(int j = 0; j < 10; j++)
    {
      ifstream inputFile("numbers.txt");
      if(inputFile){
        inputFile.close();
        remove("numbers.txt");
      }
      int randNums = rand() % 10 + 1;
      ofstream numbersFile("numbers.txt");
      string numbers = "";
      for(int i = 0; i < randNums; i++)
      {
        int num = rand() % 999 + 1;
        numbersFile << num << "\n";
        numbers += to_string(num) + "\n";
      }
      numbersFile.close();
      string expected = "File contents: " + numbers;
      string output = couttest("showNums","");
      CHECK (output == expected);
    }
  }
}

TEST_CASE("Sum numbers in a file", "[sumNumFile]")
{
  SECTION("Load and sum file")
  {
    for(int j = 0; j < 10; j++)
    {
      ifstream inputFile("numbers.txt");
      if(inputFile){
        inputFile.close();
        remove("numbers.txt");
      }
      int randNums = rand() % 10 + 1;
      ofstream numbersFile("numbers.txt");
      int total = 0; 
      for(int i = 0; i < randNums; i++)
      {
        int num = rand() % 999 + 1;
        total+=num;
        numbersFile << num << "\n";;
      }
      numbersFile.close();
      string expected = "The sum of the values in numbers.txt is " + to_string(total) + ".";
      string output = couttest("sumNumFile", expected);
      CHECK (output == expected);
      //remove("numbers.txt");
    }
  }
}

TEST_CASE("Loading contacts", "[contacts]")
{
  SECTION("Loading contacts")
  {
    for(int j = 0; j < 10; j++)
    {
      ofstream outputFile("contacts.txt");
      if(outputFile){
        outputFile.close();
        remove("contacts.txt");
      }

      int randContacts = rand() % 10 + 1;      
      string names = "";
      outputFile.open("contacts.txt");
      outputFile << randContacts << "\n";
      for(int i = 0; i < randContacts; i++)
      {
        names += nameList[i] + "\n";
        outputFile << nameList[i] << "\n";
      }
      outputFile.close();

      string expected = "What is the name of your contacts file? " + names;
      string output = couttest("contacts", "contacts.txt");
      CHECK(output == expected);
      remove("contacts.txt");
    }
  }
}
