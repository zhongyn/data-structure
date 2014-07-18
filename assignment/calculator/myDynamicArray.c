#include "myDynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct DynArr DynArr
{
	TYPE *data;
	int size;
	int capacity;
};

void _initDynArr(DynArr *v, int cap)
{
	assert(cap > 0);
	assert(v!=0);
	v->data = malloc(sizeof(TYPE)*cap);
	v->size = 0;
	v->capacity = cap;
}

DynArr *createDynArr(int cap)
{
	DynArr *v;
	assert(cap > 0);
	v = malloc(sizeof(DynArr));
	assert(v != 0);
	_initDynArr(v, cap);
}

void freeDynArr(DynArr *v)
{
	assert(v != 0);
	if (v->data != 0)		
	{
		free(v->data);
		v->data = 0;
	}
	v->size = 0;
	v->capacity =0;
}

void deleteDynArr(DynArr *v)
{
	assert(v != 0);
	freeDynArr(v);
	free(v);
}

int sizeDynArr(DynArr *v)
{
	assert(v != 0);
	return v->size;
}

void _setCapDynArr(DynArr *v, int newCap)
{
	TYPE *oldData = v->data;
	int oldSize = v->size;
	_initDynArr(v, newCap);

	for (int i = 0; i < v->size; ++i)
	{
		v->data[i] = oldData[i];
	}

	v->size = oldSize;
	free(oldData);
}

void addDynArr(DynArr *v, TYPE val)
{
	assert(v != 0);
	if (v->size >= v->capacity)
	{
		_setCapDynArr(v, 2*v->capacity);
	}
	v->data[v->size] = val;
	v->size++;
}

TYPE getDynArr(DynArr *v, int pos)
{
	assert(v != 0);
	assert(pos>=0 && pos<v->size);
	return v->data[pos];
}

void putDynArr(DynArr *v, int pos, TYPE val)
{
	assert(v != 0);
	assert(pos>=0 && pos<v->size);
	v->data[pos] = val;
}

void swapDynArr(DynArr *v, int i, int j)
{
	assert(v != 0);
	assert(i>=0 && i<v->size);
	assert(j>0 && j<v->size);
	TYPE tem;
	tem = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = tem;
}

void removeAtDynArr(DynArr *v, int idx)
{
	assert(v != 0);
	assert(idx>=0 && idx<v->size);

	while(idx<v->size-1)
	{
		v->data[idx] = v->data[idx+1];
		idx++;
	}
	v->size--;
}

int isEmptyDynArr(DynArr *v)
{
	assert(v != 0);
	return !v->size;
}

TYPE topDynArr(DynArr *v)
{
	assert(!isEmptyDynArr(v));
	return v->data[v->size-1];
}

void pushDynArr(DynArr *v, TYPE val)
{
	addDynArr(v, val);
}

void popDynArr(DynArr *v)
{
	assert(!isEmptyDynArr(v));
	removeAtDynArr(v, v->size-1);
}

void printDynArr(DynArr *v);
{
	for (int i = 0; i < v->size; ++i)
	{
		printf("array[%d] = %d\n", i, v->data[i]);
	}
}






































