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
    fCheck(fileLocation);
    }
//deconstructors    
FileCheck::~FileCheck(){  
    symStack->~GenStack();
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
                symStack->push('(');
            }
            if(line[i] == ')'){
                pRight++;
                symStack->push(')');
            }
            if(line[i] == '{'){
                cLeft++;
                symStack->push('{');
            }
            if(line[i] == '}'){
                cRight++;
                symStack->push('}');
            }
            if(line[i] == '['){
                bLeft++;
                symStack->push('[');
            }
            if(line[i] == ']'){
                bRight++;
                symStack->push(']');
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
    delimChecker();
    //close the file after accessing it
    fileLoc.close();
}
void FileCheck::delimChecker(){
    //this checks the delimeters to see if their counts match up
    if(pLeft<pRight){
        cout<<"The () does not match up "<<endl;
        message = "You are missing a ("; 
        throw runtime_error(message);  
    }
    if(pLeft>pRight){
        cout<<"The () does not match up "<<endl;
        message ="You are missing a )";
        throw runtime_error(message);
    }
    if(bLeft>bRight){
        cout<<"The [] does not match up "<<endl;
        message ="You are missing a ]";
        throw runtime_error(message);
    }
    if(bLeft<bRight){
        cout<<"The [] does not match up "<<endl;
        message = "You are missing a [";
        throw runtime_error(message);
    }
    if(cLeft<cRight){
        cout<<"The {} does not match up "<<endl;
        message = "You are missing a {";
        throw runtime_error(message);
    }
    if(cLeft>cRight){
        cout<<"The {} does not match up "<<endl;
        message ="You are missing a }";
        throw runtime_error(message);
        //after the other errors, the program checks if the user has a } for the end of the file
        if(charC.at(charCount - 1) =='}'){
           cout<<"";
        }
        if(charC.at(charCount - 1) !='}'){
            if(charC.at(charCount - 2) !='}'){
                cout<<"Reached end of file: missing } at Line "<<numLines<<endl;
                message = "";
                throw runtime_error(message);
            }
        }
        else{
            throw runtime_error(message);
        }
        
    }
    //this is what is displayed if everything is alright
    if(cLeft==cRight){
        if(bLeft==bRight){
            if(pLeft==pRight){
                cout<<"All of the delimeters are correct. Good Job!"<<endl;
            }
    }
    }
    //resets the value at the end so if another file is evaluated then the count is reset
    pLeft = 0;
    pRight = 0;
    bLeft = 0;
    bRight = 0; 
    cLeft = 0;
    cRight = 0;
}


