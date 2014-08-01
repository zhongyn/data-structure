#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	TYPE value;
	struct node *left;
	struct node *right;
};

struct BinarySearchTree
{
	struct node *root;
	int size;
};

node *_createNode(TYPE val)
{
	node *newNode = malloc(sizeof(node));
	assert(newNode != 0);
	newNode->value = val;
	newNode->left = newNode->right = 0;
	return newNode;
}

void initBST(BinarySearchTree *tree)
{
	assert(tree != 0);
	tree->root = 0;
	tree->size = 0;
}

node *_nodeAddBST(node *current, TYPE val)
{
	if (current == 0)
	{
		return _createNode(val);
	}

	if (val < current->value)
	{
		current->left = _nodeAddBST(current->left, val);
	} else if (val > current->value)
	{
		current->right = _nodeAddBST(current->right, val);
	}

	return current;
}

void addBST(BinarySearchTree *tree, TYPE val)
{
	assert(tree != 0);
	tree->root = _nodeAddBST(tree->root, val);
	tree->size++;
}

int sizeBST(BinarySearchTree *tree)
{
	assert(tree != 0);
	return tree->size;
}

TYPE _leftMostChild(node *current)
{
	while(current->left != 0)
	{
		current = current->left;
	}
	return current->value;
}

node *_removeLeftMostChild(node *current)
{
	node *tmp = current->right;

	if (current->left == 0)
	{
		free(current);
		return tmp;
	} else {
		current->left = _removeLeftMostChild(current->left);
	}
	return current;
}

node *_nodeRemoveBST(node *current, TYPE val)
{
	assert(current != 0);

	if (current->value == val)
	{
		if (current->right == 0)
		{
			node *tmp = current->left;
			free(current);
			return tmp;
		}
		current->value = _leftMostChild(current->right);
		current->right = _removeLeftMostChild(current->right);
	} else if (current->value > val)
	{
		current->left = _nodeRemoveBST(current->left, val);
	} else {
		current->right = _nodeRemoveBST(current->right, val);
	}

	return current;
}

void removeBST(BinarySearchTree *tree, TYPE val)
{
	assert(tree != 0);
	tree->root = _nodeRemoveBST(tree->root, val);
	tree->size--;
}
