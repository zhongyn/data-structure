#ifndef arrayBagStack_h
#define arrayBagStack_h

#define TYPE int
#define EQ(a,b) (a==b)

struct arrayBagStack
{
	TYPE data[100];
	int count;
};

void initArray(struct arrayBagStack *b);
void addArray(struct arrayBagStack *b, TYPE v);
int containArray(struct arrayBagStack *b, TYPE v);
void removeArray(struct arrayBagStack *b, TYPE v);
int sizeArray(struct arrayBagStack *b, TYPE v);

void pushArray(struct arrayBagStack *b, TYPE v);
TYPE topArray(struct arrayBagStack *b);
void popArray(struct arrayBagStack *b);
int isEmptyArray(struct arrayBagStack *b);
#endif
