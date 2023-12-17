#include "DEFINITIONS.h"

BinarySearchTree* CreateLeaf( BinarySearchTree* parent, int var ) {
	BinarySearchTree* NewNode = new BinarySearchTree;
	
	NewNode->value = var;
	NewNode->left = NULL;
	NewNode->right = NULL;
	NewNode->parent = parent;
	
	return NewNode;
}

void AddLeaf(BinarySearchTree** Tree, BinarySearchTree* parent, int var) {
	if(*Tree) {
		if( var >= (*Tree)->value )
			AddLeaf(&(*Tree)->right, *Tree, var);
		else
			AddLeaf(&(*Tree)->left, *Tree, var);
	}
	else
		*Tree = CreateLeaf(parent, var);
}

void DeleteTree(BinarySearchTree *Node) {
	if(Node) {
		DeleteTree(Node);
		DeleteTree(Node);
		delete Node;
	}

	return;
}

void PrintInOrder(BinarySearchTree* Tree) {
	if(Tree) {
		PrintInOrder(Tree->left);
		std::cout<<Tree->value<<" ";
		PrintInOrder(Tree->right);
	}

	return;
}