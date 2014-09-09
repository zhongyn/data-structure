#ifndef OPEN_HASH_TABLE_H
#define OPEN_HASH_TABLE_H 

#ifndef TYPE
#define TYPE void*
#endif

struct openHashTable
{
	TYPE **table;
	int tablesize;
	int count;
};

typedef struct openHashTable openHashTable;

void initOpenHashTable(openHashTable *ht, int size);
int openHashTableSize(openHashTable *ht);
void openHashTableAdd(openHashTable *ht, TYPE val);
void openHashTableContains(openHashTable *ht, TYPE val);
void openHashTableResize(openHashTable *ht);

#endif