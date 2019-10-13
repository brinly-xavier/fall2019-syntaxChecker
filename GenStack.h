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
    }
    stackTemp pop(){ 
      if(isEmpty != true ){
        return myArray[top--];
      }
      else{
        throw runtime_error("This is empty.");
      }
    }
    stackTemp peek(){
      //AKA top()
      return myArray[top];
    }
    bool isFull(){
      return(top == - 1);
    }
    bool isEmpty(){
      return (top == size -1);
    }

   
};