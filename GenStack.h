/* Brinly Xavier
Student ID: 2316142
CPSC 350-01
Assignment 03: Syntax Checker
*/

#include <iostream>
using namespace std;

template <class stackTemp>
class GenStack
{
    
  public:
    int size;
    int top;
    stackTemp *myArray;//this is a pointer
    
    GenStack(){
      //initialization of default values
      myArray = new stackTemp[128];
      size = 128;
      top = -1;
    }

    GenStack(int maxSize){//overloaded constructor
      myArray = new stackTemp[maxSize];
      size = maxSize;
      top = -1;
    }

    ~GenStack(){
       delete myArray;
     }//destructor

    void push(stackTemp d){
      myArray[++top] = d;
      //this takes in an element and places it into the top of the stack
    }
    stackTemp pop(){ 
      if(isEmpty() != true ){
        //if this is not empty then the top of the stack is returned and removed
        return myArray[top--];
      }
      else{
        throw runtime_error("This is empty.");
      }
    }
    stackTemp peek(){
      //just returns the top of the stack
      return myArray[top];
    }
    bool isFull(){
      //this checks if the stack is full or not
      return(top == - 1);
    }
    bool isEmpty(){
      //this also checks the size of the stack and
      //makes sure that it is not empty
      return (top == size -1);
    }

   
};