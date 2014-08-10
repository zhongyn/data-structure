#include "avl.h"
#include <stdlib.h>
#include <assert.h>


struct AVLnode
{
	TYPE value;
	AVLnode *left;
	AVLnode *right;
	int height;
};

// return the height of current node
int h(AVLnode *cur)
{
	if (cur == 0)
	{
		return -1;
	}
	return cur->heigth;
}

// set heigth for current node
void setHeight(AVLnode *cur)
{
	int lh = h(cur->left);
	int rh = h(cur->right);

	if (lh < rh)
	{
		cur->heigth = rh + 1;
	} else {
		cur->heigth = lh + 1;
	}
}

// add node to AVL tree and return current node
AVLnode* AVLnodeAdd(AVLnode *cur, TYPE val)
{
	if (cur == 0)
	{
		AVLnode *newNode = malloc(sizeof(AVLnode));
		assert(newNode != 0);
		newNode->value = val;
		newNode->left = newNode->right = 0;
		newNode->heigth = 0;
		return newNode;
	} else if (val < cur->val)
	{
		cur->left = AVLnodeAdd(cur->left, val);
	} else {
		cur->right = AVLnodeAdd(cur->right, val);
	}
	return balance(cur);
}

// return balance factor for current node
int bf(AVLnode *cur)
{
	return h(cur->left) - h(cur->right);
}

// balance the tree and return current node
AVLnode* balance(AVLnode *cur)
{
	int cbf = bf(cur);
	if (cbf < -1)
	{
		if (bf(cur->left) > 1)
		{
			rotateLeft(cur->left);
		}
		return rotateRight(cur);
	} else if (cbf > 1)
	{
		if (bf(cur->right) < -1)
		{
			rotateRight(cur->right)
		}
		return rotateLeft(cur);
	}

	setHeight(cur);
	return cur;
}

// rotate left the tree and return current node
AVLnode* rotateLeft(AVLnode *cur)
{
	AVLnode *tmp = cur->right;
	cur->right = tmp->left;
	tmp->left = cur;
	setHeight(cur);
	setHeight(tmp)
	return tmp;
}

// rotate right the tree and return current node
AVLnode* rotateRight(AVLnode *cur)
{
	AVLnode *tmp = cur->left;
	cur->left = tmp->right;
	tmp->right = cur;
	setHeight(cur);
	setHeight(tmp)
	return tmp;	
}

// remove value in avltree
void removeAVLTree(AVLTree *tree, TYPE val)
{
	tree->root = removeNode(tree->root, val);
	tree->cnt--;
}

// return left most value
TYPE leftMost(AVLnode *cur)
{
	while (cur->left != 0)
	{
		cur = cur->left;
	}
	return cur->value;
}

// remove left most node
AVLnode* removeLeftMost(AVLnode *cur)
{
	if (cur->left == 0)
	{
		AVLnode *tmp = cur->right;
		free(cur);
		return tmp;
	}
	cur->left = removeLeftMost(cur->left);
	return balance(cur);
}

// remove node
AVLnode* removeNode(AVLnode *cur, TYPE val)
{
	if (val == cur->value)
	{
		if (cur->right == 0)
		{
			AVLnode *tmp = cur->left;
			free(cur);
			return tmp;
		}
		cur->value = leftMost(cur->right);
		cur->right = removeLeftMost(cur->right);
	} else if (val < cur->left)
	{
		cur->left = removeNode(cur->left, val);
	} else{
		cur->right = removeNode(cur->right, val);
	}
	return balance(cur);
}
