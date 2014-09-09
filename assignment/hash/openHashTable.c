#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "openHashTable.h"

void initOpenHashTable(openHashTable *ht, int size)
{
	assert(size>0);
	ht->table = (TYPE **)malloc(size*sizeof(TYPE *));
	assert(ht->table != 0);
	for (int i = 0; i < size; ++i)
	{
		ht->table[i] = 0;
	}

	ht->tablesize = size;
	ht->count = 0;
}

int openHashTableSize(openHashTable *ht)
{
	return ht->size;
}

void openHashTableAdd(openHashTable *ht, TYPE val)
{
	if (ht->count/(double)ht->tablesize > 0.75)
	{
		openHashTableResize(ht);
	}

	int hashIndex = HASH(val)%openHashTableSize(ht);
	if (hashIndex < 0)
	{
		hashIndex += openHashTableSize;
	}

	while(ht->table[hashIndex] != 0)
	{
		hashIndex++;
		if (hashIndex == ht->tablesize)
		{
			hashIndex = 0;
		}
	}

	ht->table[hashIndex] = val;
}

void openHashTableContains(openHashTable *ht, TYPE val)
{
	int hashIndex = HASH(val)%openHashTableSize(ht);
	if (hashIndex < 0)
	{
		hashIndex += openHashTableSize(ht);
	}

	while(ht->table[hashIndex] != 0)
	{
		if (EQ(val, ht->table[hashIndex]))
		{
			return 1;
		} else {
			hashIndex++;
			if (hashIndex == ht->tablesize)
			{
				hashIndex = 0;
			}
		}
	}
	return 0;
}

void openHashTableResize(openHashTable *ht)
{
	int oldSize = ht->tablesize;
	openHashTable *oldht = ht;
	initOpenHashTable(ht, 2*oldSize);
	int hashIndex;

	for (int i = 0; i < oldSize; ++i)
	{
		if (oldht->table[i] != 0)
		{
			openHashTableAdd(ht, oldht->table[i]);
		}
	}

	free(oldht->table);
	free(oldht);
}

