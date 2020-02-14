
#include "stdafx.h"
#include "MyArray.h"
#include <Windows.h>

//testing our programm
int main()
{
	printf("M1 is:\n");
	MyArray m1(10);
	m1.PrintAddr();
	m1.Rnd();
	m1.Print();
	cin.get();

	printf("\nM2 is:\n");
	MyArray m2 = m1;
	m2.PrintAddr();
	m2.Print();
	cin.get();

	printf("\nM3 is:\n");
	MyArray m3(5);
	cout << &m3 << endl;
	m3.PrintThis();
	m3.Rnd();
	m3.Print();
	cin.get();

	printf("\nNew m1 is:\n");
	m1 = m3;
	m1.PrintAddr();
	m1.Print();
	printf("M1.sum is: %d\n", m1.Sum());
	printf("M1[2] is: %d\n", m1[2]);
	printf("M1 is: %d\n", m1);
	printf("M1++ is: %d\n", m1++);
	m1.Print();
	printf("++M1 is: %d\n", ++m1);
	m1.Print();
	string s = (string)m1;
	MessageBoxA(0, s.c_str(), "content", 0);
	cin.get();

    return 0;
}

