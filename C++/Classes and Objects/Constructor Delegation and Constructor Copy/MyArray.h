//Header File for the Class. Prototypes.

#pragma once

#include <iostream>

using namespace std;

class MyArray
{

//Class variable are private by default
//Declaring pointer for array and it's size
	int *p; 
	size_t sizeArr; 

public:

  //Default Constructor
	MyArray();
  
  //Constructor wich takes single parametr
	MyArray(const size_t &);
  
  //Constructor copy. Takes object of same class as parametr
	MyArray(const MyArray &);
  
  //Printing the memory address just for shown. 
	void PrintAddr(void); 
  
  //Same as above. different syntax
	void PrintThis(void); 
  
  //function to randomize values in the our array
	void Rnd(void);
  
  //function to print por array to the screen
	void Print(void);
  
  //Destructor
	~MyArray();
};

