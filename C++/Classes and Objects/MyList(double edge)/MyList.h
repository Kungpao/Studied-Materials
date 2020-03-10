#pragma once
#include <iostream>

// double edged list
class MyList
{
	// making a core
public:	struct Node
	{
		int i;
		Node *pNext;
		Node *pPrev;
	};
	
private:
	Node *pHead, *pTail;

	//method and constructor/destructor prototypes
public:
	MyList();
	~MyList();
	void Add(const int&);
	Node* Insert(Node*, const int &);
	bool IsEmpty(void)const
	{
		return !this->pHead;
	}
	void Print(void) const;
	void PrintReverse(void)const;
	Node *Find(const int&)const;
};

