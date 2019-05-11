#include "BST.h"
#include <iostream>

BST::BST() {
	root = NULL;
	root->leftNode = root->rightNode = NULL;
}

BST::~BST() {
	delete root;
}

Node *BST::createNode(unsigned int data) {
	Node *node = new Node;
	node->data = data;
	node->leftNode = node->rightNode = NULL;
	return node;
}

void BST::addNode(Node *& rt, unsigned int data) {
	if (rt == NULL)
		rt = createNode(data);
	else if (data > root->data)
		addNode(rt->rightNode, data);
	else
		addNode(rt->leftNode, data);
}

//find the key and return it
//root -> left -> right
Node *BST::preOrderSearch(Node *& rt, unsigned int x) {
	Node *traverse = rt;

	if (traverse == NULL || traverse->data == x)
		return traverse;
	else if (x > traverse->data)
		return preOrderSearch(rt->rightNode, x);
	else
		return preOrderSearch(rt->leftNode, x);
}



