#include "stdafx.h"
#include "A.h"
#include <iostream>
using namespace std;

int main()
{
	A a;
	a.Set(10);
	cout << a.Get() << endl;
	
	a.Set("Testing str set/get ");
	cout << a.GetStr() << endl;

	//strcpy_s(a.GetStr(), 9, "hi hat");  will not work because we made a.GetStr() a const

	/*cout << a.GetStr();*/
    return 0;
}
