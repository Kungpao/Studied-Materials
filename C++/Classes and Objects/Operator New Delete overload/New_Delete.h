#pragma once
#include <iostream>
using namespace std;
class A
{
public:
	
	A();
	~A();

	//operator new overload prototype
	void *operator new(size_t); 

	//operator delete overload
	void operator delete(void *, size_t );

};

