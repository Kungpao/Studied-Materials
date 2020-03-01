#include "stdafx.h"
#include <iostream>
#include "MyStack.h"




int main()
{
	//creating object of MyStack
	MyStack mst;

	//pushing some values into stack
	for (int i = 0; i < 5; i++)
	{
		mst.Push(i);
	}
	

	//We cannot reach value other than last one present in it.
	// To reach other values we need to clear our way up to them.

	//while (!mst.IsEmpty())
	//	std::cout << mst.Pop() << std::endl;


    return 0;
}

