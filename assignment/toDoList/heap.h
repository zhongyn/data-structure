#ifndef HEAP_H
#define HEAP_H

# ifndef TYPE
# define TYPE      void*
# endif

int compare(TYPE left, TYPE right);

void heapRemoveFirst(struct dynArr *h);
void adjustHeap(struct dynArr *h, int max, int pos);
void swap(struct dynArr *h, int i, int j);
int indexSmallest(struct dynArr *h, int i, int j);
TYPE heapGetFirst(struct dynArr *h);
void heapAdd(struct dynArr *h, TYPE val);

#endif