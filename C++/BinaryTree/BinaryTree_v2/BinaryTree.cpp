#include "stdafx.h"
#include "BinaryTree.h"

//setting default values
BinaryTree::BinaryTree(void) : pRoot(NULL), TreeSize(NULL)
{

}
//TreeClearing procedure
BinaryTree::~BinaryTree(void)
{
	if (this->pRoot)
		this->Clear(this->pRoot);
}

RESULT BinaryTree::AddNode(const int& i)
{
	RESULT result = ERROR;
	//checking if Node is already Exist. if it is not:
	if (!this->pRoot)
	{
		this->pRoot = new Node;
		//quick memory allocation check
		if (!this->pRoot)
			return result;
		this->pRoot->i = i;
		this->pRoot->pLeft = this->pRoot->pRight = NULL;
	}
	//if it is already exist:
	else
	{
		//Searching for insert position
		Node *pSearchPos = this->pRoot,
			*pPrevPos = NULL;
		//until pSearchPos == 0 keeps search
		while (pSearchPos)
		{
			pPrevPos = pSearchPos;
			//Searching for conjuction. if it hits:
			if (pSearchPos->i == i)
				return EXIST;
			// otherwise keeps searchig. moving left 
			else if(pSearchPos->i>i)
			{
				pSearchPos = pSearchPos->pLeft;
			}
			//or right
			else
			{
				pSearchPos = pSearchPos->pRight;
			}

		}
		//making a Node
		Node *pNewNode = new Node;
		if (!pNewNode)
			return result;
		//setting it's values
		pNewNode->i = i;
		pNewNode->pLeft = pNewNode->pRight = NULL;

		//making conection with previous Node to complete the tree structure
		if (pPrevPos->i > pNewNode->i)
			pPrevPos->pLeft = pNewNode;
		else 
			pPrevPos->pRight = pNewNode;
	}
	//increasing size value by one
	this->TreeSize++;

	return OK;
}

//RemoveNode Method body 
void BinaryTree::RemoveNode(const int&i)
{
	// Check for tree is empty
	if (!this->pRoot)
		return;
	// else proceeding deeper. Deleteting by rewriting pointer with result of recursive removeNode method
	this->pRoot=this->RemoveNode(this->pRoot, i);
}

//Remove Node recursive method body
Node *BinaryTree::RemoveNode(	Node *pNode,	//pointer to the tree element
								const int &i)	//value to remove
{
	//Searching for the Node to remove
	//recursion default exit case
	if (!pNode)
		return NULL;
	//searching to the left
	else if (pNode->i > i)
	{
		 pNode->pLeft=this->RemoveNode(	pNode->pLeft,
												i);
	}
	//searching to the right
	else if (pNode->i < i)
		 pNode->pRight=this->RemoveNode(	pNode->pRight,
												i);
	//if we have found the Node in question
	else
	{
		//making tmp remove pointer
		Node *pRemoveNode = pNode;
		//if there is no subnode to the left, just reconnecting our nodes with existing one
		//right
		if (!pRemoveNode->pLeft)
			pNode = pRemoveNode->pRight;
		//or left
		else if (!pRemoveNode->pRight)
			pNode = pRemoveNode->pLeft;

		//otherwise there are two subnodes are present.
		else
		{
			//making another tmp pointer
			Node *pFind = pNode->pLeft;
			// unti we meet the null
			if (pFind->pRight)
			{
				//Moving to the right until NULL
				while (pFind->pRight->pRight)
					pFind = pFind->pRight;
				//rewriting value of node
				pNode->i = pFind->pRight->i;

				//saving it's pointer
				pRemoveNode = pFind->pRight;

				//rewriting it's pointers to go to the left
				//pFind->pRight = pFind->pRight->pLeft;
				pRemoveNode = pRemoveNode->pLeft;

			}
			//we have meet the null
			else
			{
				//rewriting  our value with founded one
				pNode->i = pFind->i;
				//cleaning purpose
				pRemoveNode = pFind;
				//turning 
				pNode->pLeft = pNode->pLeft->pLeft;
			}

		}
		//cleaning tmp pointers
		delete pRemoveNode;
		pRemoveNode = NULL;
		//edditing size of the tree
		this->TreeSize--;
	}

	return pNode;
}
//Method for return current Size of the tree
int BinaryTree::GetSize(void) const
{
	return this->TreeSize;
}

//Print Method with variant for printing variant possibility. 
void BinaryTree::PrintTree(const bool &variant) const
{
	//false = printing in string;
	if (!variant)
	{
		this->RecPrint(this->pRoot);
	}
	//printing as "tree"
	else
	{
		this->RecPrint(this->pRoot, NULL);
	}
}
//Printing in string variant
void BinaryTree::RecPrint(const Node *pNode) const
{
	//if pointer is not NULL
	if (pNode)
	{
		//calling itself with it's pLeft parameter.
		this->RecPrint(pNode->pLeft);
		//printing value
		std::cout << pNode->i << " ";
		//calling itself with pRight parameter
		this->RecPrint(pNode->pRight);
	}
}
//Printing in "Tree" variant
void BinaryTree::RecPrint(	const Node *pNode,			// pointer for tree element
							const int &level) const		//tree element level
{
	//if pointer is not NULL
	if (pNode)
	{
		//calling itself with pLeft parameter, tree element level
		this->RecPrint(pNode->pLeft, level + 1);
		//printing spaces. count of spaces is equal to level of the element in the tree
		for (int i = 0; i < level; i++)
			std::cout << " ";
		//printing value
		std::cout << pNode->i << std::endl;
		//calling itself with pRight parameter, tree element level
		this->RecPrint(pNode->pRight, level + 1);
	}

}
//clear method to use in ~BinaryTree
void BinaryTree::Clear(void) 
{
	//calling recursive clear method
	this->Clear(this->pRoot);
	this->pRoot = NULL;
	this->TreeSize = NULL;
}
//Clear method recursive body
void BinaryTree::Clear(Node *pNode)
{
	//if pointer is not NULL
	if (pNode)
	{
		//clearing it's pLeft
		this->Clear(pNode->pLeft);
		//than it's pRight
		this->Clear(pNode->pRight);
		//clearing pointer itself
		free(pNode);
		//then setting it to NULL
		pNode = NULL;
	}
}
