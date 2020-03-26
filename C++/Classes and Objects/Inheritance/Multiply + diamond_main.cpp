#include "stdafx.h"
#include <iostream>


//multiply inheritance + diamond inheritance
//C++ does nt create diamond inheritance structure by default, thats why there will be always two defferet subclasses. 
//to make it work properly we need to put virtual on the way til the parrent.

class A
{
protected:
	int i;
public:
	void Set(const int &value)
	{
		this->i = value;
	}
	int Get(void) const
	{
		return this->i;
	}
};

class B:  virtual public A {};

class C :  virtual public A {};

class D : virtual public C, virtual public B {};


int main()
{
		D d;
		d.C::Set(77);
		std::cout << d.B::Get() << std::endl;
		return 0;
}

