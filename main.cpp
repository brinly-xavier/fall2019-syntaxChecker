/* Brinly Xavier
Student ID: 2316142
CPSC 350-01
Assignment 03: Syntax Checker
*/
#include "fileCheck.h"
#include <iostream>
#include <fstream>

using namespace std;
string fileLocation;
string loop = "yes";

int main(int argc, char **argv){

//this loops through the program until the user does not want to assuming that there are no errors
  while(loop == "yes"){
    //this takes the filename as a command line argument
    fileLocation = argv[1];  
    try{
      FileCheck checker(fileLocation);
      cout<<"All of the syntax is good."<<endl;
   }
    catch(runtime_error e){
      //this runtime error ends the program once the first error is detected
      cout<<e.what()<<endl;
      cout<<"Fix your mistake and come back!\n"<<endl;
      return 0;
   }
    cout<<"Would you like to go again?(yes/no)"<<endl;
    //this question is asked to see if the user wants to loop through the program once all
    //of the errors in a file is fixed 
    cin>>loop;
    if(loop == "yes"){
      cout<<"Please enter the location of a file you would like to work with"<<endl;
      cin>>fileLocation;
    }
  }
  //the program ends
  cout<<"GoodBye!"<<endl;
  return 0;
  
}