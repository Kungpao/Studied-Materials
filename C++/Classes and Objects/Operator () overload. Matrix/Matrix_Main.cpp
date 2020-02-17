// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Matrix.h"


int main()
{
	Matrix m;

	cout << "First test: " << endl;
	m.Matrix_Rnd();
	m.Matrix_Print();

	cout << "Second test: " << endl;
	m(1, 1) = 100;
	m.Matrix_Print();

	cout << "third test: " << endl;
	cout << m.operator()(1, 1) << endl;
	

	cout << "fourth test: " << endl;
	m();
	m.Matrix_Print();

    return 0;
}

