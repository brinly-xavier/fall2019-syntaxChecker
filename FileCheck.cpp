/* Brinly Xavier
Student ID: 2316142
CPSC 350-01
Assignment 03: Syntax Checker
*/
#include "FileCheck.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int pLeft, pRight, bLeft, bRight, cLeft, cRight;
int numLines;
int charCount;
string charC;
string message;
ifstream fileLoc;
//constrctor for checking the file
FileCheck::FileCheck(string fileLocation){
    //the stack of delimiters for the file is created
    symStack = new GenStack<char>();
    //the stack of counting the location of the delimeters
    numStack = new GenStack<int>();
    numLines = 0;
    //this runs the check based on the file
    fCheck(fileLocation);
    }
//deconstructors    
FileCheck::~FileCheck(){  
    symStack->~GenStack();
    numStack->~GenStack();
}
void FileCheck::fCheck(string fileLocation){
    //this opens the file
    fileLoc.open(fileLocation);
    if (fileLoc.is_open())
    {
        cout<< "File successfully open\n"<<endl;
    }
    else
    {
        throw runtime_error("The file you entered could not be opened. Try again Later.");
    }
    string line;
    //this while loops adds all the delimeters to the stack
    //it counts each type of delimeter
    while(getline(fileLoc, line)){
        numLines++;
        for(int i = 0; i < line.length(); ++i){
            if(line[i] == '('){
                pLeft++;
                //this takes the delimeter and the location of it and places them into stacks
                symStack->push('(');
                numStack->push(numLines);
            }
            if(line[i] == ')'){
                pRight++;
                symStack->push(')');
                numStack->push(numLines);
            }
            if(line[i] == '{'){
                cLeft++;
                symStack->push('{');
                numStack->push(numLines);
            }
            if(line[i] == '}'){
                cRight++;
                symStack->push('}');
                numStack->push(numLines);
            }
            if(line[i] == '['){
                bLeft++;
                symStack->push('[');
                numStack->push(numLines);
            }
            if(line[i] == ']'){
                bRight++;
                symStack->push(']');
                numStack->push(numLines);
            }
            if(line[i] != ' '){
                charCount++;
                charC+=line[i];
            }
    }   
    }
    
    cout<<"pLeft: "<<pLeft<<endl;
    cout<<"pRight: "<<pRight<<endl;
    cout<<"cLeft: "<<cLeft<<endl;
    cout<<"cRight: "<<cRight<<endl;
    cout<<"bLeft: "<<bLeft<<endl;
    cout<<"bRight: "<<bRight<<"\n"<<endl; 
    //this is explained in the next section
    delimConseq();
    //close the file after accessing it
    fileLoc.close();
}
void FileCheck::delimConseq(){
    //this runs through the delimeters in the stack and checks for opens and closes
    for(int currIn = 0; currIn <= symStack->top; ++currIn){
        //this sets the current delimeter based on where the loop is in the stack
        char currDel = symStack->myArray[currIn];
        //this goes through the stack
       for(int i = 0; i <= symStack->top; ++i) {
           if(pLeft == pRight){
               if(cLeft == cRight){
                   if(bLeft == bRight){
                       break;
                   }
            }
           }
           if(currDel == '('){
               //conditions for the current delimeter
               if(symStack->myArray[i] == ')'){
                   break;
               }
               //the program breaks once an error is found
               if(symStack->myArray[i] == '}'){
                   cout<<"Expected ) found }";
                   cout<<" at line "<<numStack->myArray[i];
                   //this will then go through the stack and try to find it a pair
                   throw runtime_error(message);
               }
               if(symStack->myArray[i] == ']'){
                   cout<<"Expected ) found ]";
                   cout<<" at line"<<numStack->myArray[i];
                   throw runtime_error(message);
               }
           }
           if(currDel == '['){
               if(symStack->myArray[i] == ']'){
                   break;
               }
               if(symStack->myArray[i] == '{'){
                   cout<<"Expected ] found {";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
               if(symStack->myArray[i] == ')'){
                   cout<<"Expected ] found )";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
           }
           if(currDel == '{'){
               if(symStack->myArray[i] == '}'){
                   break;
               }
               if(symStack->myArray[i] == ')'){
                   cout<<"Expected } found )";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
               if(symStack->myArray[i] == ']'){
                   cout<<"Expected } found ]";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
           }
            if(currDel == ')'){
               if(symStack->myArray[i] == '('){
                   break;
               }
               if(symStack->myArray[i] == '{'){
                   cout<<"Expected ( found {";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
               if(symStack->myArray[i] == '['){
                   cout<<"Expected ( found [";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
           }
           if(currDel == ']'){
               if(symStack->myArray[i] == '['){
                   break;
               }
               if(symStack->myArray[i] == '{'){
                   cout<<"Expected [ found {";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
               if(symStack->myArray[i] == '('){
                   cout<<"Expected [ found (";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
           }
           if(currDel == '}'){
               if(symStack->myArray[i] == '{'){
                   break;
               }
               if(symStack->myArray[i] == '['){
                   cout<<"Expected { found [";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
               if(symStack->myArray[i] == ')'){
                   cout<<"Expected { found )";
                   cout<<" at line "<<numStack->myArray[i];
                   throw runtime_error(message);
               }
           }
           //this checks the end of the file to make sure that the code ends with a } 
           //and if it does not then an error will show up
            if(charC.at(charCount - 1) !='}'){
                if(charC.at(charCount - 2) !='}'){
                    cout<<"At end of file: missing }"<<endl;
                    throw runtime_error(message);
            }
        }
       }
    }
    //the counters are reset each time a file is analyzed
    pLeft = 0;
    pRight = 0;
    bLeft = 0;
    bRight = 0; 
    cLeft = 0;
    cRight = 0;
}



