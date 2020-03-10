// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyList.h"

int main()
{
	MyList L;

	std::cout << "Added some numbers to the list:" << std::endl;
	for (size_t i = 0; i < 3;i++)
		L.Add(i);

	std::cout << "Print left to right:" << std::endl;
	L.Print();

	std::cout << "Print right to left:" << std::endl;
	L.PrintReverse();

	std::cout << "Searching the position with index = 2:" << std::endl;
	MyList::Node *p = L.Find(2);
	if (p)
	{
		std::cout << "Done!" << std::endl;
		std::cout << "Inserting value 777 in position:" << std::endl;
		L.Insert(p, 777);
		L.Print();
		std::cout << "Printing reversed format:" << std::endl;
		L.PrintReverse();
	}
	else
		std::cout << "Failed" << std::endl;
    return 0;
}

