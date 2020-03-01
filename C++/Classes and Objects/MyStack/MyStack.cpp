#include "stdafx.h"
#include "MyStack.h"


//MyStack::MyStack()
//{
//
//}

//DESTRUCTOR body realization
MyStack::~MyStack()  // способ очистки стека. 
{
	Node *p = this->pTop;
	while (p)
	{
		std::cout << "Destructing: " <<p->i<< std::endl;
		this->pTop = p->pNext;
		delete p;
		p = this->pTop;
		
	}
	std::cout << std::endl << "Destructor Done" << std::endl;
}

//void method Push realization
void MyStack::Push(const int &i)  // добавление елементов в стек
{
	//dynamic memory allocation for a new element
	Node*pNew = new Node(i);
	//if there is no previous element, setting this one as Top
	if (!this->pTop)
		this->pTop=pNew;

	//remaking bonds
	else
	{
		pNew->pNext = this->pTop;
		this->pTop = pNew;
	}
	std::cout << "Was pushed: " << this->pTop->i << std::endl;
}

//int method Pop realization
int MyStack::Pop(void) // метод извлечения елементов из стека
{

	int iRet = this->pTop->i;
	Node *pRemove = this->pTop;
	this->pTop = pRemove->pNext;
	delete pRemove;
	return iRet;
}
