#ifndef AVL_H
#define AVL_H

#ifndef TYPE
#define TYPE int;
#endif

typedef struct AVLnode AVLnode;

// return the height of current node
int h(AVLnode *cur);

// set heigth for current node
void setHeight(AVLnode *cur);

// add node to AVL tree and return current node
AVLnode* AVLnodeAdd(AVLnode *cur, TYPE val);

// return balance factor for current node
int bf(AVLnode *cur);

// balance the tree and return current node
AVLnode* balance(AVLnode *cur);

// rotate left the tree and return current node
AVLnode* rotateLeft(AVLnode *cur);

// rotate right the tree and return current node
AVLnode* rotateRight(AVLnode *cur);

// remove value in avltree
void removeAVLTree(AVLTree *tree, TYPE val);

// return left most value
TYPE leftMost(AVLnode *cur);

// remove left most node
AVLnode* removeLeftMost(AVLnode *cur);

// remove node
AVLnode* removeNode(AVLnode *cur, TYPE val);


#endif