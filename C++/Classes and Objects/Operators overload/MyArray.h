#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class MyArray
{
	//pointer
	int *p; 
	//arraySize
	size_t ArrSize;

public:
	//Constructor default
	MyArray();

	//Constructor wich takes a parametr
	MyArray(const size_t &);
	
	//Constructor Copy
	MyArray(const MyArray &);
	
	//Method prototypes
	void PrintAddr(void); 
	void PrintThis(void); 
	void Rnd(void);
	void Print(void);
	
	//overloads
	int Sum(void)const;
	
	//method for return size of MyArray
	const size_t& Size(void)const
	{
		return this->ArrSize;
	}

	//operator == overload
	//we can also put realizations right in .h file but it not nice
	bool operator ==(const MyArray&m) const 
	{
		bool f = this->Sum() == m.Sum();
		return f;
	}

	// operator [] overload const
	const int & operator [](const size_t &i)const 																						
	{
		return this->p[i];
	}
	// operator [] overload no const
	int & operator [](const size_t &i)
	{
		return this->p[i];
	}

	// operator ++val
	MyArray &operator ++ (); // для ++ префиксом

	//operator val++
	MyArray operator ++ (int);// для ++ постфиксом

	//operator =
	const MyArray &operator = (const MyArray&); 

	// operator typecast to STL string
	operator string() const;

	//DESTRUCTOR
	~MyArray();
};

