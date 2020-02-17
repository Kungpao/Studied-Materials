#pragma once
#include <iostream>

using namespace std;

class Matrix
{	
	//Static matrix declaration
	int m[10][10];

public:
	//constructor and destructor
	Matrix();
	~Matrix();
	
	//some functions
	void Matrix_Rnd();
	void Matrix_Print();

	//operator () overload
	const int &operator()(const size_t&, const size_t&)const;	
	int &operator()(const size_t&, const size_t&);
	void operator()();

};
