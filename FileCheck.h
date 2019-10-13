/* Brinly Xavier
Student ID: 2316142
CPSC 350-01
Assignment 03: Syntax Checker
*/
#include "GenStack.h"
#include <iostream>

using namespace std;

class FileCheck
{
  public:
  FileCheck(string fileLocation);//constructor
  ~FileCheck();//deconstructor
  GenStack <char>* symStack; //the stack that counts all the delimeters
  void fCheck(string fileLocation);//method does the checking
  void delimChecker(); //checks for the delimeters
};