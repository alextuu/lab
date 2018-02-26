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
#include "functions.hpp"
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


TEST_CASE("Factorial", "[factorial]")
{
  SECTION("Factorial")
  {
    for(int j = 0; j < 10; j++)
    {
      int randNums = rand() % 13;
      int fact = 1;
      for(int i = randNums; i > 0; i--)
        fact*=i;
      CHECK(fact == factorial(randNums));
    }
  }
}

TEST_CASE("Name exists", "[nameExists]")
{
  SECTION("Name exists")
  {
    for(int i = 0; i< 10; i++)
    {
      string nameList[10] = {"John Lennon", "Paul McCartney", "George Harrison", "Ringo Starr", "Diana Ross", "Mary Wilson", "Florence Ballard", "Cindy Birdsong", "Jean Terrell", "Susaye Greene"};
      int randNums = rand() % 10 + 1;
      int randName = rand() % randNums;
      CHECK(nameExists(nameList, randNums, nameList[randName]) == true);
      CHECK(nameExists(nameList, randNums, "Invalid name") == false);
    }
  }
}

TEST_CASE("Find contact from file", "[findContactFile]")
{
  SECTION("Finding position of a key in an array")
  {
    for(int i = 0; i < 10; i++)
    {
      string nameList[10] = {"John Lennon", "Paul McCartney", "George Harrison", "Ringo Starr", "Diana Ross", "Mary Wilson", "Florence Ballard", "Cindy Birdsong", "Jean Terrell", "Susaye Greene"};
      int randNums = rand() % 10 + 1;
      int randName = rand() % randNums;
      CHECK(findName(nameList, randNums, nameList[randName]) == randName);
      CHECK(findName(nameList, randNums, "Invalid name") == -1);
    }
  }
  SECTION("Finding position of a key in a file")
  {
    for(int i = 0; i < 10; i++)
    {
      string nameList[10] = {"John Lennon", "Paul McCartney", "George Harrison", "Ringo Starr", "Diana Ross", "Mary Wilson", "Florence Ballard", "Cindy Birdsong", "Jean Terrell", "Susaye Greene"};
      int randNums = rand() % 10 + 1;

      ofstream outputFile("contacts.txt");
      if(outputFile){
        outputFile.close();
        remove("contacts.txt");
      }
 
      string names = "";
      outputFile.open("contacts.txt");
      outputFile << randNums << "\n";
      for(int i = 0; i < randNums; i++)
      {
        names += nameList[i] + "\n";
        outputFile << nameList[i] << "\n";
      }
      outputFile.close();
      int randName = rand() % randNums;
      CHECK(findContactFile("contacts.txt", nameList[randName]) == randName);
      CHECK(findContactFile("contacts.txt", "Invalid name") == -1);
    }
  }
}