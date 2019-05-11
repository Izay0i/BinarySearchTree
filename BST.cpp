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

Node *BST::findMax(Node *&rt) {
	while (rt->rightNode != NULL)
		rt = rt->rightNode;
	return rt;
}

Node *BST::findMin(Node *&rt) {
	while (rt->leftNode != NULL)
		rt = rt->leftNode;
	return rt;
}

Node *BST::removeNode(Node *&rt, unsigned int x) {
	Node *tempNode;
	
	if (rt == NULL)
		return rt;
	else if (x > rt->data)
		rt->rightNode = removeNode(rt->rightNode, x);
	else if (x <= rt->data)
		rt->leftNode = removeNode(rt->leftNode, x);
	else {
		if (rt->leftNode == NULL && rt->rightNode == NULL) {
			delete rt;
			rt = NULL;
		}
		else if (rt->rightNode == NULL) { 
			tempNode = rt;
			rt = rt->leftNode;
			delete tempNode;
		}
		else if (rt->leftNode == NULL) {
			tempNode = rt;
			rt = rt->rightNode;
			delete tempNode;
		}
		else {
			tempNode = findMin(rt->rightNode);
			rt->data = tempNode->data;
			rt->rightNode = removeNode(rt->rightNode, tempNode->data);
		}
	}
	return rt;
}

