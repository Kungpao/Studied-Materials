
#include "stdafx.h"
#include <iostream>
#include"User.h"

using namespace std;

//Regular function search for Min value. 
float Min(const float*, const size_t &); 

//Template function prototypes
//Template function. Searching for min value
template <class T, class V>
T Min(const T*, const V&);

//template function. Searching for max value
template <class T, class V>
T Max(const T*, const V&);

//Template function. Sorting
template <class T, class V>
void Sort( T*, const V&);

//Template function. Swap
template <class T>
void Swap( T&,  T&);

//Template function. Print
template <class T, class V>
void Print(const T*, const V&);

int main()
{
	int arr[] = { 77,3,88,8,99 };
	int d = 0;
	int c = 2;

	// явное инстанциирование	шаблонов;
	cout << "Min is: "<< Min<int>(arr, sizeof(arr) / sizeof(int)) << endl; 
	cout << "Max is: "<< Max<int>(arr, sizeof(arr) / sizeof(int)) << endl;

	Print(arr, sizeof(arr) / sizeof(int));
	cout << endl << endl;

	cout << "Sorted arr:" << endl;
	Sort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
	cout << endl << endl;

	
	cout << "Swaped arr:" << endl;
	Swap(arr[0], arr[4]);
	Print(arr, sizeof(arr) / sizeof(int));
	cout << endl << endl;

	User u[] = { User("Peter",20), User("John",45), User("Frenk",25) };
	cout << Min(u, sizeof(u) / sizeof(User)) << endl;
	cout << Max(u, sizeof(u) / sizeof(User)) << endl;
	cout << endl << endl;

	cout << "basic User array" << endl;
	Print(u, sizeof(u) / sizeof(User));
	cout << endl << endl;

	cout << "swapped User array" << endl;
	Swap(u[0], u[2]);
	Print(u, sizeof(u) / sizeof(User));
	cout << endl << endl;

	cout << "sorted User array" << endl;
	Sort(u, sizeof(u) / sizeof(User));
	Print(u, sizeof(u) / sizeof(User));
	cout << endl << endl;
    return 0;
}

//Function bodies
float Min(const float*p, const size_t &s)
{
	float iMin = p[0];
	for (size_t i = 0; i < s;i++)
	{
		if (iMin > p[i])
			iMin = p[i];
	}
	return iMin;
}

//template bodies
template <class T,class V>
T Min(const T *p, const V &s)
{

	T tMin = *p;
	for (V i = 0; i < s;i++)
	{
		if (tMin > p[i])
			tMin = p[i];
	}
	return tMin;
}

template <class T, class V>
T Max(const T *p, const V &s)
{
	T tMax = *p;
	for (V i = 0; i < s;i++)
	{
		if (tMax < p[i])
			tMax = p[i];
	}
	return tMax;
}

template <class T, class V>
void Sort( T *p, const V &s)
{
	//temporal variable for tracking present array value
	T temp; 

	//variable to keep track of index 
	int item; 
	for (int i = 1; i < s; i++)
	{
		//remembering current array value
		temp = p[i]; 
		//remembering index
		item = i - 1; 
		//making loop for searching min value of array
		while (item >= 0 && p[item] > temp) 
		{
			//rearranging
			p[item + 1] = p[item]; 
			p[item] = temp;
			item--;
		}
	}
}

template <class T>
void Swap( T &p, T &s)
{
	T tmp=p;
	p = s;
	s = tmp;	
}

template <class T, class V>
void Print(const T *p, const V &s)
{
	for (int i = 0; i < s;i++)
		cout << p[i] << " ";
	cout << endl;
}
