#include "myDynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct DynArr
{
	TYPE *data;
	int size;
	int capacity;
	int beg;
};

void _initDynArr(DynArr *v, int cap)
{
	assert(cap > 0);
	assert(v!=0);
	v->data = malloc(sizeof(TYPE)*cap);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = cap;
	v->beg = 0;
}

DynArr *createDynArr(int cap)
{
	DynArr *v;
	assert(cap > 0);
	v = malloc(sizeof(DynArr));
	assert(v != 0);
	_initDynArr(v, cap);
	return v;
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
	v->beg = 0;
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

int _absoluteId(DynArr *v, int id)
{
	if (v->beg < 0)
	{
		v->beg += v->capacity;
	}
	return (id+v->beg) % v->capacity;
}

void _setCapDynArr(DynArr *v, int newCap)
{
	TYPE *oldData = v->data;
	int oldSize = v->size;
	_initDynArr(v, newCap);

	for (int i = 0; i < v->size; ++i)
	{
		v->data[i] = oldData[_absoluteId(v,i)];
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
	v->data[_absoluteId(v,v->size)] = val;
	v->size++;
}

TYPE getDynArr(DynArr *v, int pos)
{
	assert(v != 0);
	assert(pos>=0 && pos<v->size);
	return v->data[_absoluteId(v,pos)];
}

void putDynArr(DynArr *v, int pos, TYPE val)
{
	assert(v != 0);
	assert(pos>=0 && pos<v->size);
	v->data[_absoluteId(v,pos)] = val;
}

void swapDynArr(DynArr *v, int i, int j)
{
	assert(v != 0);
	assert(i>=0 && i<v->size);
	assert(j>0 && j<v->size);
	TYPE tem;
	i = _absoluteId(v,i);
	j = _absoluteId(v,j);
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
		v->data[_absoluteId(v,idx)] = v->data[_absoluteId(v,idx+1)];
		idx++;
	}
	v->size--;
}

// Stack interface
int isEmptyDynArr(DynArr *v)
{
	assert(v != 0);
	return !(v->size);
}

TYPE topDynArr(DynArr *v)
{
	assert(!isEmptyDynArr(v));
	return v->data[_absoluteId(v,v->size-1)];
}

void pushDynArr(DynArr *v, TYPE val)
{
	addDynArr(v, val);
}

void popDynArr(DynArr *v)
{
	assert(!isEmptyDynArr(v));
	v->size--;
}

void printDynArr(DynArr *v);
{
	for (int i = 0; i < v->size; ++i)
	{
		printf("array[%d] = %d\n", i, v->data[_absoluteId(v,i)]);
	}
}

// Bag interface
int containsDynArr(DynArr *v, TYPE val)
{
	assert(v != 0);
	assert(!isEmptyDynArr(v));

	for (int i = 0; i < v->size; ++i)
	{
		if (v->data[_absoluteId(v,i)] == val) return 1;
	}
	return 0;
}

void removeDynArr(DynArr *v, TYPE val)
{
	assert(v != 0);
	for (int i = 0; i < v->size; ++i)
	{
		if (v->data[_absoluteId(v,i)] == val)
		{
			removeAtDynArr(v,i);
			break;
		}
	}
}

<<<<<<< HEAD
// Deque interface
void addFrontDynArr(DynArr *v, TYPE val)
{
	assert(v != 0);
	if (v->size >= v->capacity)
	{
		_setCapDynArr(v, 2*v->capacity);
	}
	v->beg = v->beg-1;
	v->data[_absoluteId(v,0)] = val;
	v->size++;
}

void removeFrontDynArr(DynArr *v)
{
	assert(v != 0);
	v->beg++;
	v->size--;
}

void addBackDynArr(DynArr *v, TYPE val)
{
	assert(v != 0);
	addDynArr(v, val);
}

void removeBackDynArr(DynArr *v)
{
	assert(v != 0);
	v->size--;	
}

TYPE frontDynArr(DynArr *v)
{
	assert(v->size >0);
	return v->data[_absoluteId(v,0)];
}

TYPE backDynArr(DynArr *v)
{
	return v->data[_absoluteId(v,v->size-1)];
}

=======
int _binarySearch(TYPE *data, int size, TYPE val)
{
	int low = 0;
	int high = size;
	int mid;
	while (low<high)
	{
		mid = (low+high)/2;
		if (LT(data[mid], val))
		{
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}
>>>>>>> 5247510f09a7a704168c072a4964e288425ceb5b

int binarySearchDynArr(DynArr *v, TYPE val)
{
	return _binarySearch(v->data, v->size, val);
}

void addAtDynArr(DynArr *v, int id, TYPE val)
{
	assert(id>=0 && id<=v->size);
	if (v->size >= v->capacity)
	{
		_setCapDynArr(v, 2*v->capacity);
	}
	for (int i = v->size-1; i>=id; i--)
	{
		v->data[i+1] = v->data[i];
	}
	v->data[id] = val;
}

void addOrderedDynArr(DynArr *v, TYPE val)
{
	int id = binarySearchDynArr(v, val);
	addAtDynArr(v, id, val);
}

int containOrderedDynArr(DynArr *v, TYPE val)
{
	int id = binarySearchDynArr(v, val);

	if (id < v->size)
	{
		if (EQ(v->data[id], val))
		{
			return 1;
		}
	}
	return 0;
}

void removeOrderedDynArr(DynArr *v, TYPE val)
{
	int id = binarySearchDynArr(v, val);
	if (id<v->size && EQ(v->data[id], val))
	{
		removeAtDynArr(v, id);
	}
}




































