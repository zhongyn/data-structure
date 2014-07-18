/* 	dynArrDeque.h : Dynamic Array with Stack, Queue, Deque implementation. */
#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1

# define TYPE int
# define EQ(a, b) (a == b)


typedef struct DynArr DynArr;

/* Dynamic Array Functions */
void initDynArr(DynArr *v, int capacity);	
DynArr *createDynArr(int cap);

void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);

int sizeDynArr(DynArr *v);

void addDynArr(DynArr *v, TYPE val);
TYPE getDynArr(DynArr *v, int pos);
void putDynArr(DynArr *v, int pos, TYPE val);
void swapDynArr(DynArr *v, int i, int  j);
void removeAtDynArr(DynArr *v, int idx);

/* Stack interface. */
int isEmptyDynArr(DynArr *v);
void pushDynArr(DynArr *v, TYPE val);
TYPE topDynArr(DynArr *v);
void popDynArr(DynArr *v);

/* Bag Interface */	
int containsDynArr(DynArr *v, TYPE val);
void removeDynArr(DynArr *v, TYPE val);

/* Deque Interface */
void addFrontDynArr(DynArr *v, TYPE val);
void removeFrontDynArr(DynArr *v);
void addBackDynArr(DynArr *v, TYPE val);
void removeBackDynArr(DynArr *v);
TYPE frontDynArr(DynArr *v);
TYPE backDynArr(DynArr *v);

#endif