#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <iostream>

struct BinarySearchTree {
	int value;
	BinarySearchTree* left;
	BinarySearchTree* right;
	BinarySearchTree* parent;
};

BinarySearchTree* CreateLeaf( BinarySearchTree* parent, int var );
void AddLeaf(BinarySearchTree** Tree, BinarySearchTree* parent, int var);
void DeleteTree(BinarySearchTree *Node);
void PrintInOrder(BinarySearchTree* Tree);

#endif
