#pragma once

#include <iostream>

//struct for making Nodes of the tree;
struct Node
{
	int i;
	Node *pLeft;
	Node *pRight;
};

//short enum for errors handling. Codes for results of add method
enum RESULT
{
	ERROR = -1,
	EXIST,
	OK
};

//Class declaration
class BinaryTree
{

public:

	//default constructor/destructor
	BinaryTree(void);
	~BinaryTree(void);

	//add method by value
	RESULT AddNode (const int&);
	//return BinaryTree total size
	int GetSize (void) const;
	//remove method by value
	void RemoveNode (const int&);
	//clear tree method
	void Clear (void);
	//printing total tree. = false means print as string(default case), =true - print as a tree;
	void PrintTree(const bool& = false)const;


private:
	//variables
	Node *pRoot;
	int TreeSize;

	//print methods.
	void RecPrint(	const Node*	)const;

	void RecPrint(	const Node*,		//pointer to the tree element
					const int&) const;		//element level in the tree
	
	//recursive RemoveNode method
	Node *RemoveNode(	Node*,			//pointer to the element in the tree
						const int&);	//node value
	
	//recursive Clear method
	void Clear(Node *);

	

};
