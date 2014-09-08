#ifndef HASH_TABLE_H
#define HASH_TABLE_H 

struct hlink
{
	TYPE value;
	struct link *next;
};

struct hashTable
{
	struct hlink **table;
	int count;
	int tablesize; 
};

void initHashTable(struct hashTable *ht, int size);
int hashTableSize(struct hashTable *ht);
void hashTableAdd(struct hashTable *ht, TYPE newValue);
int hashTableContains(struct hashTable *ht, TYPE value);
void hashTableRemove(struct hashTable *ht, TYPE value);
void resizeTable(struct hashTable *ht);

#endif