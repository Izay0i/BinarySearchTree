#pragma once

#include "Node.h"

class BST {
private:
	Node *root;
	Node *createNode(unsigned int data);
public:
	BST();
	~BST();

	//*& reference of pointer to root
	void addNode(Node *&rt, unsigned int data);
	Node *removeNode(Node *&rt, unsigned int x);
	Node *preOrderSearch(Node *&rt, unsigned int x);
	Node *findMin(Node *&rt);
};
