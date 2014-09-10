/* 	dynArr.h : Dynamic Array implementation. */
#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1


# ifndef TYPE
# define TYPE      void*
# endif


struct dynArr
{
	TYPE *data;
	int size;
	int capacity;	
	int beg;
};

typedef struct dynArr dynArr;

//struct dynArr
//{
//	TYPE *data;		/* pointer to the data array */
//	int size;		/* Number of elements in the array */
//	int capacity;	/* capacity ofthe array */
//};

/* Dynamic Array Functions */
dynArr *createDynArr(int cap);
void deleteDynArr(dynArr *v);
int sizeDynArr(dynArr *v);
void addDynArr(dynArr *v, TYPE val);
TYPE getDynArr(dynArr *v, int pos);
void putDynArr(dynArr *v, int pos, TYPE val);
void swapDynArr(dynArr *v, int i, int  j);
void removeAtDynArr(dynArr *v, int idx);
void addAtDynArr(dynArr *v, int id, TYPE val);
void pushDynArr(dynArr *v, TYPE val);
TYPE topDynArr(dynArr *v);
void popDynArr(dynArr *v);
int isEmptyDynArr(dynArr *v);
void printDynArr(dynArr *v);
// int binarySearchDynArr(dynArr *v, TYPE val);
// void addOrderedDynArr(dynArr *v, TYPE val);
// int containOrderedDynArr(dynArr *v, TYPE val);
// void removeOrderedDynArr(dynArr *v, TYPE val);

#endif