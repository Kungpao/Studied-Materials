
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "MyVector.h"
#include "MyVector1.h"
#include "MyMatrix.h"

//just because of lazy to type std:: in a small study program
using namespace std;

int main()
{
	//random values generation
	srand(time(0));

	//template class's main pro is that we can put whatever type we need in '< >' and use it however we wish
	MyVector<char> v(10); 

	for (size_t i = 0;i<v.Size();i++)
	{
		v[i] = rand() % 100;
		cout << v[i] << " ";
	}
	cout << endl;

	//typedefing the long name into the short one. We made it confusing on purpose. To show that we need to be really careful with typedef names
	typedef MyVector1<> String; 

	String str;
	str[0] = 'd';

	MyMatrix<int> m;

	for (size_t i = 0; i < m.Rows();i++)
	{
		for (size_t j = 0; j < m.Cols();j++)
		{
			m(i,j) = i + j;
			cout << m(i, j) << " ";
		}
		cout << endl;
	}


    return 0;
}

