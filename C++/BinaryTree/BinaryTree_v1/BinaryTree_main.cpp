// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinTree.h"

int main()
{
	//creating object of BinTree class
	BinTree bt;

	//checking its functionality
	//add method
	std::cout << "Binary tree made!" << std::endl;
	bt.Add(7);
	bt.Add(1);
	bt.Add(4);
	bt.Add(3);
	bt.Add(2);
	bt.Add(10);
	std::cout << "Our binary tree is:" << std::endl;
	bt.Print();
	std::cout << std::endl;
	
	//some more
	bt.Add(15);
	bt.Add(5);
	bt.Add(100);
	std::cout << "Edit#1 binary tree is:" << std::endl;
	bt.Print();
	std::cout << std::endl;

	//checking find() method
	std::cout << "Edit#2 binary tree find(5) is:" << std::endl;
	std::cout << bt.Find(5)->i << std::endl;

	//checking find() method for non-existing value
	std::cout << "Edit#2 binary tree find(6) is:" << std::endl;
	if(bt.Find(6))
		std::cout << bt.Find(6)->i<< std::endl;
	else
		std::cout << "Find(6) Failed" << std::endl;
	
	//checking erase() method
	std::cout << "Edit#3 binary tree Erase(5) is:" << std::endl;
	bt.Erase(5);
	bt.Print();
	std::cout << std::endl;

	//declaring success
	std::cout << "Done!" << std::endl;
    return 0;
}

