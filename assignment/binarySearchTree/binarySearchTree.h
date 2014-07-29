#ifndef BST_H
#define BST_H 1


# ifndef TYPE
# define TYPE int
# endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

typedef struct node node;
typedef struct BinarySearchTree BinarySearchTree;

void initBST(BinarySearchTree *tree);
void addBST(BinarySearchTree *tree, TYPE val);
int sizeBST(BinarySearchTree *tree);
void removeBST(BinarySearchTree *tree, TYPE val);

# endif