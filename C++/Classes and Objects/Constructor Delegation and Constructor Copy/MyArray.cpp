// MyArray.cpp file

#include "stdafx.h"

//includ our header file to use
#include "MyArray.h"

//Default constructor. Set fields to 0
MyArray::MyArray():p(0),sizeArr(0)
{

}

//Constructor takes a size, delegetion to default constructor, then makes own work
MyArray::MyArray(const size_t &s): MyArray() 
{
  //Set size
	this->sizeArr = s; 
  //Set memory
	this->p = new int[this->sizeArr]; 
}

//Constructor Copy. Receiving same class object as parametr and copying it's field to himself
MyArray::MyArray(const MyArray &m):MyArray()
{
  //size
	this->sizeArr = m.sizeArr;
  //memory allocation
	this->p = new int[this->sizeArr];
  //values
	memcpy_s(this->p, this->sizeArr * sizeof(int), m.p, m.sizeArr * sizeof(int));
}

//Print pointer address func body
void MyArray::PrintAddr(void)
{
	cout << this->p << endl;
}

//Same as above but diferent realization
void MyArray::PrintThis()
{
	cout << this << endl;
}

//Rnd func body
void MyArray::Rnd(void)
{
	for (size_t i = 0; i < this->sizeArr; i++)
		this->p[i] = rand() % 1000;
}

//Print func body
void MyArray::Print(void)
{
	for (size_t i = 0; i < this->sizeArr; i++)
		cout << this->p[i] << " ";
}

//destructor body realization
MyArray::~MyArray()
{
	delete[]this-p;
}
