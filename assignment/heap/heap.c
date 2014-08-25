#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArr.h"


void heapRemoveFirst(dynArr *h)
{
	int last = sizeDynArr(h) - 1;
	assert(last != 0);
	putDynArr(h, 0, getDynArr(h, last));
	removeAtDynArr(h, last);
	adjustHeap(h, last, 0);
}

void adjustHeap(struct dynArr *h, int max, int pos)
{
	int leftid = pos*2 + 1;
	int rightid = pos*2 + 2;

	if (rightid < max)
	{
		int id = indexSmallest(h, leftid, rightid);
		if (compare(getDynArr(h, pos), getDynArr(h, id)) == 1)
		{
			swapDynArr(h, pos, id);
			adjustHeap(h, max, id);
		}
	} else if (leftid < max){
		if (compare(getDynArr(h, pos), getDynArr(h, leftid)) == 1)
		{
			swapDynArr(h, pos, leftid);
		}
	}
}

void heapAdd(struct dynArr *h, TYPE val)
{
	assert(h != 0);
	addDynArr(h, val);

	int child = sizeDynArr(h) - 1;
	int parent = floor((child - 1)/2);
	while (compare(getDynArr(h, child), getDynArr(h, parent)) == 1)
	{
		swapDynArr(h, child, parent);
		child = parent;
		parent = floor((child - 1)/2);
		if (parent < 0) break;
	}
}

int indexSmallest(struct dynArr *h, int i, int j)
{
	if (compare(getDynArr(h,i), getDynArr(h,j)) == 1)
	{
		return j;
	}
	return i;
}

TYPE heapGetFirst(struct dynArr *h)
{
	assert(sizeDynArr(h) > 0);
	return getDynArr(h, 0);
}

