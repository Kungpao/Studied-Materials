#pragma once
#include "DoubleGrafic.h"

//inheritance. DoubleGraphic is parent. 
class Child:public Parrent
{
private:
	int c;

public:
	//default constructor
	Child();
	//constructor wich takes params
	Child(const int&, const int&, const int&);
	//overloading << operator to print our class's fields
	friend std::ostream&operator<<(std::ostream &os, const Child &tg)
	{
		os << "X=" << tg.a << ",Y= " << tg.b << ",Z=" << tg.c << std::endl;
		return os;
	}
	//default destructor
	~Child();
};
