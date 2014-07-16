// arrayBagstack.c
// Copyright 2014 Oegon State University. All rights reserved.

#include "arrayBagStack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


// This function allocates space for an arrayBagStack structure
struct arrayBagStack *createArray()
{
	struct arrayBagStack *b = malloc(sizeof(struct arrayBagStack));
	return b;
}

void initArray(struct arrayBagStack *b)
{
	b->count = 0;
}

void addArray(struct arrayBagStack *b, TYPE v)
{
	b->data[b->count] = v;
	b->count++;
}

int containArray(struct arrayBagStack *b, TYPE v)
{
	for (int i = 0; i < b->count; i++)
	{	
		if (EQ(b->data[i],v))return 1;
	}
	return 0;
}

void removeArray(struct arrayBagStack *b, TYPE v)
{
	int i = 0;
	int j;
	assert(containArray(b,v));

	while(!EQ(b->data[i++],v));
	for (j = i; j < b->count-1; j++)
	{
		b->data[j] = b->data[j+1];
	}
	b->count -= 1;
}

int sizeArray(struct arrayBagStack *b, TYPE v)
{
	return b->count;
}

void pushArray(struct arrayBagStack *b, TYPE v)
{
	addArray(b,v);
}

TYPE topArray(struct arrayBagStack *b)
{
	assert(!isEmptyArray(b));
	return b->data[b->count-1];
}

void popArray(struct arrayBagStack *b)
{
	assert(!isEmptyArray(b));
	b->count--;
}

int isEmptyArray(struct arrayBagStack *b)
{
	return (!b->count);
}

void printArray(struct arrayBagStack *b)
{
	for (int i = 0; i < b->count; ++i)
	{
		printf("Array[%d] = %d\n", i, b->data[i]);
	}
}