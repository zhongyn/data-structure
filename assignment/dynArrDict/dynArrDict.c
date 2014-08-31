#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArrDict.h"

void dynArrDictGet(DynArr *v, KEYTYPE key, VALUETYPE *vapt)
{
	assert(dynArrDictContainsKey(v, key) == 1);

	for (int i = 0; i < v->size; ++i)
	{
		if (compare(v->data[i]->key, key) == 0)
		{
			*vapt = v->data[i]->value;
		}
	}
}

void dynArrDictPut(DynArr *v, KEYTYPE key, VALUETYPE value)
{
	struct association *kv;

	if (dynArrDictContainsKey(v, key))
	{
		dynArrDictRemoveKey(v, key);
	}

	assert(kv != 0);
	kv->key = key;
	kv->value = value;
	addDynArr(v, kv);
}

int dynArrDictContainsKey(DynArr *v, KEYTYPE key)
{
	assert(isEmptyDynArr(v) != 0);

	for (int i = 0; i < v->size; ++i)
	{
		if (compare(v->data[i]->key, key) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void dynArrDictRemoveKey(DynArr *v, KEYTYPE key)
{
	for (int i = 0; i < v->size; ++i)
	{
		if (compare(v->data[i]->key, key) == 0)
		{
			removeAtDynArr(v, i);
		}
	}
}
