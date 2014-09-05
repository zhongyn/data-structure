#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashTable.h"


void initHashTable(struct hashTable *ht, int size)
{
	assert(ht!=0);
	ht->(table) = (struct hlink**)malloc(sizeof(struct hlink*)*size);
	assert(*table!=0);
	ht->count = 0;
	ht->tablesize = size;

	for (int i = 0; i < size; ++i)
	{
		ht->table[i] = 0;
	}
}

int hashTableSize(struct hashTable *ht)
{
	return hashTable->count;
}

void hashTableAdd(struct hashTable *ht, TYPE newValue)
{
	int hashIndex = HASH(newValue)%ht->tablesize;
	if (hashIndex < 0)
	{
		hashIndex += ht->tablesize;
	}

	struct hlink *newLink = malloc(sizeof(struct link));
	assert(newLink != 0);
	newLink->value = newValue;
	newLink->next = ht->table[hashIndex];
	ht->table[hashIndex] = newLink;
	ht->count++;
	if (ht->count/(double)ht->size) > 8.0	
	{
		resizeTable(ht);
	}
}

int hashTableContains(struct hashTable *ht, TYPE value)
{
	int hashIndex = HASH(newValue)%ht->tablesize;
	if (hashIndex < 0)
	{
		hashIndex += ht->tablesize;
	}

	struct hlink *tmp;
	tmp = ht->table[hashIndex];
	while (tmp != 0)
	{
		if (compare(tmp->value, value) == 0)
		{
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

void hashTableRemove(struct hashTable *ht, TYPE value)
{
	int hashIndex = HASH(newValue)%ht->tablesize;
	if (hashIndex < 0)
	{
		hashIndex += ht->tablesize;
	}

	struct hlink *current;
	struct hlink *previous;

	if (hashTableContains(ht, value))
	{
		previous = ht->table[hashIndex]; 
		current = ht->table[hashIndex];

		while (current != 0)
		{
			if (compare(current->value, value) == 0)
			{
				if (current == ht->table[hashIndex])
				{
					ht->table[hashIndex] = current->next;
				} else {
					previous->next = current->next;
				}
				free(current);
				current = 0;
			} else {
				previous = current;
				current = current->next;
			}
		}
	}
}

void resizeTable(struct hashTable *ht)
{
	
}
