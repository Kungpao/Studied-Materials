// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyArray.h"

int main()
{
	//Testing
	printf("M1 is:\n");
	MyArray m1(10);
	m1.PrintAddr();
	m1.Rnd();
	m1.Print();
	cin.get();

	printf("M2 is:\n");
	MyArray m2 = m1;
	m2.PrintAddr();
	m2.Print();
	cin.get();

	printf("M is:\n");
	MyArray m;
	cout << &m << endl;
	m.PrintAddr();
	m.Print();
	cin.get();
	
	printf("M3 is:\n");
	MyArray m3(11);
	m3.PrintAddr();
	m3.Rnd();
	m3.Print();
	cin.get();
    return 0;
}

