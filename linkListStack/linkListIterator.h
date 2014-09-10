#ifndef link_list_iterator_h
#define link_list_iterator_h 1

#include "linkListDeque.h"

typedef linkListIterator linkListIterator;

linkListIterator* createLinkListIterator(linkListDeque *list);
int linkListIteratorHasNext(linkListIterator *itr);
TYPE linkListIteratorNext(linkListIterator *itr);
void linkListIteratorRemove(linkListIterator *itr);



#endif
