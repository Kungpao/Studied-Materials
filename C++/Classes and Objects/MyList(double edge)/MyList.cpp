#include "stdafx.h"
#include "MyList.h"

//set initialization values to Null
MyList::MyList():pHead(nullptr),pTail(nullptr) 
{
}

//destructor. realization
MyList::~MyList() 
{
	//tmp pointer to the head of the list
	Node *p = this->pHead; 
	//until p exists
	while (p)
	{
		//moving forvard
		this->pHead = p->pNext;
		//deleting
		delete p;
		p = this->pHead;
	}
}

//add new node method
void MyList::Add(const int &i) 
{
	Node *p = new Node{ i, nullptr,nullptr };

	//if null, then head and tail are equal
	if (!this->pHead) 
	{
		this->pHead = this->pTail = p;
		return;
	}
	//if not empty remaking bonds
	this->pTail->pNext = p; 
	//tail becomes equal to previous
	p->pPrev = this->pTail; 
	//new pointer is become tail
	this->pTail = p; 
}

//inser method
MyList:: Node* MyList:: Insert(MyList::Node *pos, const int &i)
{
	Node *p = new Node{ i,nullptr,nullptr };

	//if equals then moving everything to the right side. new node becomes head
	if (pos == this->pHead) // если позиция равна голове, сдвигаем все вправо, новое теперь голова.
	{
		p->pNext = this->pHead;
		this->pHead->pPrev = p;
		this->pHead = p;
	}

	else if (pos == this->pTail)
	{
		p->pNext = this->pTail;
		p->pPrev = this->pTail->pPrev;
		
		//last element has a pointer on previous one, but previous one has a pointer to the next one, wich becomes equal to a new one.
		this->pTail->pPrev->pNext = p;
		this->pTail -> pPrev = p;
	}

	else 
	{
		// next from previous becomes new
		p->pPrev -> pNext = p;
		//this previous becomes previous from before
		p->pPrev = pos->pPrev; 
		//previous from before becomes new
		pos->pPrev = p; 
		//and becomes pos
		p->pNext = pos;
	}
	return p;
}

// method to print values from head to tail
void MyList::Print(void)const
{
	const Node*p = this->pHead;
	while (p)
	{
		std::cout << p->i << " ";
		p = p->pNext;
	}
	std::cout << std::endl;
}
//method to print values from tail to head
void MyList::PrintReverse(void)const
{
	const Node*p = this->pTail;
	while (p)
	{
		std::cout << p->i << " ";
		p = p->pPrev;
	}
	std::cout << std::endl;
}
//method to search and set up a position
MyList::Node *MyList::Find(const int&i)const	
{
	Node *p = this->pHead;
	while (p)
	{
		if (p->i == i)
			return p;
		p = p->pNext;
	}
	return nullptr;
}
