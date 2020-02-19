#pragma once
#include <memory.h>
#include <iostream>
#include <ostream>
#include <istream>

using namespace std;

//Declaring our class to work with
class User
{	
//privat fields
	char strName[20];
	int iAge;
	int iSize;

public:
  //Constructor default
	User();
  //Constructor with parametr
	User(const char *p, const int &i):iAge(i)
	{
		strcpy_s(this->strName, 19, p);
	}
  //operator > overload
	bool operator >(const User &u) const
	{
		return this->iAge > u.iAge;
	}
  //operator < overload
	bool operator <(const User &u) const
	{
		return this->iAge < u.iAge;
	}
  //operator << overload
	friend ostream&operator <<(ostream &, const User &);

	int Size(const User *p)
	{
		return this->iSize = sizeof(p) / sizeof(User);
	}

	~User();
};
