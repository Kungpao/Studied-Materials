#pragma once
#include <iostream>

//class my stack
class MyStack
{
	// Struct for keeping integer value and pointer for the next element of list
	struct Node 
	{

		int i;
		Node *pNext;
		//Constructor wich takes parameters
		Node(const int &i=0,Node *p=nullptr):i(i),pNext(p)
		{

		}
	};

	//pointer for the Top element of list
	Node *pTop;

public:

	//constructor default
	MyStack(void) :pTop(nullptr)
	{

	}
	//DESTRUCTOR
	~MyStack(void);

	//Boolean method for check isEmpty
	bool IsEmpty(void) const
	{
		return !this->pTop;
	}

	//void Push method prototype
	void Push(const int&);

	//int Pop method prototype
	int Pop(void);
};

