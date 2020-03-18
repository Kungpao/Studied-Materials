#include "stdafx.h"
#include "BinTree.h"

//Default. set root to nullptr
BinTree::BinTree():pRoot(nullptr)
{
}

//Clearing tree by recursion
BinTree::~BinTree()
{
	if(this->pRoot)
		this->Clear(this->pRoot); 
}

//Add Node method
BinTree::Node* BinTree::Add(const int &i)
{

	return this->Add(&this->pRoot, i);
	 
}
//Hidden add Node method
BinTree::Node* BinTree::Add(Node**pNode, const int &i)
{
	Node *p = *pNode;

	//if p is first call then p == root
	if (!p)
	{
		p = new Node{ i,nullptr,nullptr };
		*pNode = p;
		return p;
	}

	// if value is less -  going left
	if (i < p->i) 
	{
		return this->Add(&p->pLeft, i);
	}

	// if value is bigger - going right
	else if (i > p->i)
		return this->Add(&p->pRight, i);

	// otherwise just returns 
	else
		return p;
}
//Search Node method
BinTree::Node *BinTree::Find(const int &i)const
{
	return this->Find(this->pRoot, i);
}

//Hidden search method
BinTree::Node*BinTree::Find(Node *p, const int &i)const
{
	//exit condition if recieved pointer == 0
	if (!p)
	{
		return NULL;	
	}
	//if <i going right then repeat
	if (p->i < i)
	{
		return this->Find(p->pRight, i);
	}
	//if >i going left then repeat
	else if (p->i>i)
		return this->Find(p->pLeft, i);

	//Exit condition which means we have found what we searched
	else
		return p;

}

//Erase Node method
void BinTree::Erase(const int &i)
{
	//saving find result node pointer
	Node *TmpFind = this->Find(i);
	
	//if value was found proceeding
	if (TmpFind)		
		 this->Erase(TmpFind, i);	

	//Else showing error message
	else
	{
		std::cout << "Erase() failed" << std::endl;
	
	}
	

}

//Our hiden Erase method
void BinTree::Erase(Node *pNode, const int &i)
{
	// Saving copy of Node that we want to delete
	Node *TmpRemoveNode = pNode;
	
	// if it doesnt have right subNode, rewriting it with left subNode
	if (!TmpRemoveNode->pRight)
		pNode = TmpRemoveNode->pLeft;
		
	// Else if, making for opposite case
	else if (!TmpRemoveNode->pLeft)
		pNode = TmpRemoveNode->pRight;

	//Else our node has both subNodes
	else
	{
		// new pointer for searching connection point
		Node *pTmpFind = pNode->pLeft;
		
		// if there are another subnode
		if (pTmpFind->pRight)
		{

			// Moving to the right until meet Null
			while (pTmpFind->pRight->pRight)
				pTmpFind = pTmpFind->pRight;

			//saving value we have found 
			pNode->i = pTmpFind->pRight->i;

			// saving pointer for a new subNode
			TmpRemoveNode = pTmpFind->pRight;

			// recconecting Nodes 
			pTmpFind->pRight = pTmpFind->pRight->pLeft;

		}
		//Else there are no more subNodes
		else
		{
			// rewriting value
			pNode->i = pTmpFind->i;

			// connecting  our tmp pointers 
			TmpRemoveNode = pTmpFind;

			// now filling the gap 
			pNode->pLeft = pNode->pLeft->pLeft;
		}

	}
	//clearing memory
	delete TmpRemoveNode;
	TmpRemoveNode = NULL;

}
//Print Method
void BinTree::Print(void)const
{
	this->Print(this->pRoot);
}

//Hidden print Method
void BinTree::Print(const Node*p)const
{
	//printing with recursion until !p
	if (p)
	{
		//drilling to the left
		this->Print(p->pLeft);
		//start to print
		std::cout << p->i << std::ends;
		//visiting right
		this->Print(p->pRight);
	}
}
//clear Method
void BinTree::Clear(Node*p)
{
	//if there are pointer exististing
	if (p)
	{
		//clearing its left side
		this->Clear(p->pLeft);
		//next right side
		this->Clear(p->pRight);
		//deleteting pointer
		delete p;
		p = NULL;
	}
}
