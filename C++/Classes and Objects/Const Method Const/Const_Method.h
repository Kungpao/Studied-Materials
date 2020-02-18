#pragma once
#include <memory.h>
#include <iostream>
class A
{
	//private: by default
	int i;
	char s[20];

public:
	A();

	//Set self i
	void Set(const int &i) 
	{
		this->i = i;
	}

	//Return self i
	int Get(void) const
	{
		return this->i;
	}

	//Set overload
	void Set(const char *s)
	{
		strcpy_s(this->s, sizeof(this->s) - 1, s);
	}

	//Return self str
	const char *GetStr(void) const 
	{
		return this->s;
	}

	//Destructor
	~A();
};

