#pragma once
#include <iostream>
#include <ostream>

//creating a class wich will becom furute parrent to another class
class Parrent
{
protected:
	int a, b;
public:
	//default constructor
	Parrent();
	//constructor wich takes params
	Parrent(const int&, const int&);
	//overloading << operator to print this class's fields
	friend std::ostream& operator <<(std::ostream &os, const Parrent &cl)
	{
		os << "X=" << cl.a << ", Y=" << cl.b;
		return os;
	}
	//default constructor
	~Parrent();
};

