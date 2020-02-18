#include "stdafx.h"
#include "A.h"
#include <iostream>

using namespace std;
int main()
{

	A a;
	B b;
	C c;

	//Setting B class value by A class function
	a.Set(b);

	//Setting C class value by A class function
	a.Set(c);

	//Printing
	cout << b.Get() << endl << c.Get() << endl;
    return 0;
}

