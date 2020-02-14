#include "stdafx.h"
#include "MyArray.h"

//MyArray Methods and Constructors Realization
//Constructors
//Constructor Default
MyArray::MyArray():p(0),ArrSize(0)
{

}
//Constructor with a parametr. Delegion to default first
MyArray::MyArray(const size_t &s): MyArray() 
{
	this->ArrSize = s; 
	this->p = new int[this->ArrSize];
}

//Constructor copy
MyArray::MyArray(const MyArray &m):MyArray()

{
	this->ArrSize = m.ArrSize;
	this->p = new int[this->ArrSize];
	memcpy_s(this->p, this->ArrSize * sizeof(int), m.p, m.ArrSize * sizeof(int));
}

//Methods
//Return adress
void MyArray::PrintThis()
{
	cout << this << endl;
}
//same as above. different syntax
void MyArray::PrintAddr(void)
{
	cout << this->p << endl;
}

//Randomize
void MyArray::Rnd(void)
{
	for (size_t i = 0; i < this->ArrSize; i++)
		this->p[i] = rand() % 1000;
}
//Print
void MyArray::Print(void)
{
	for (size_t i = 0; i < this->ArrSize; i++)
		cout << this->p[i] << " ";
	cout << endl;
}

//Operator overloads
int MyArray::Sum(void) const
{
	int iSum = 0;
	for (int i = 0; i < this->ArrSize; i++)
		iSum += this->p[i];
	return iSum;
}

//Operator = realization
const MyArray &MyArray::operator = (const MyArray &m) 														
{
	//if both are equal no point to continue. just returning our *
	if(this == &m)
		return *this;
	//clearing old data
	delete[]this->p;
	//resize
	this->ArrSize = m.ArrSize;
	//allocating memory with a new size
	this->p = new int [m.ArrSize];
	//copy values
	memcpy_s(this->p, sizeof(int)*this->ArrSize, m.p, sizeof(int)*m.ArrSize);
	//returning new *
	return *this;
}

MyArray&MyArray:: operator++()
{
	for (size_t i = 0; i < this->ArrSize; i++)
		++this->p[i];
	return *this;
}

MyArray MyArray::operator++(int)
{
	MyArray tmp(*this);
	for (size_t i = 0; i < this->ArrSize; i++)
	{
		this->p[i]++;

	}
	return tmp;
}

MyArray::operator string()const
{
	ostringstream stream;
	for (size_t i = 0; i < this->ArrSize; i++)
		stream << this->p[i] << " ";
	return stream.str();
}

//DESTRUCTOR
MyArray::~MyArray()
{
	delete[]this->p; // освобождение памяти.
}
