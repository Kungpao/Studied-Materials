#pragma once
#include <iostream>

class BinTree
{
public:
	//node
	struct Node
	{
		int i;
		Node *pLeft;
		Node *pRight;
	};

	//default prototypes
	BinTree();
	~BinTree();

	//few key methods
	Node *Add(const int &);
	Node *Find(const int&)const;
	void Erase(const int &);
	void Print(void)const;

	//made like this to not give the user the tree root
private: 
	Node *pRoot;
	Node *Add(Node**, const int &);
	Node *Find(Node*, const int &)const;
	void Erase(Node*, const int &);
	void Print(const Node*)const;

	//hidden method to call in destructor for total desustruction of the tree
	void Clear(Node*);
};

