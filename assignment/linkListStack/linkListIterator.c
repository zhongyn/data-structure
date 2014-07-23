#include "linkListIterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct linkListIterator
{
	linkListDeque *list;
	link *currentLink;
};

linkListIterator* createLinkListIterator(linkListDeque *lst)
{
	linkListIterator *itr;
	itr = malloc(sizeof(linkListIterator));
	itr->list = lst;
	itr->currentLink = lst->firstlink;
	return itr;
}

int linkListIteratorHasNext(linkListIterator *itr)
{
	return (itr->currentLink != itr->list->lastlink);
}

TYPE linkListIteratorNext(linkListIterator *itr)
{
	assert(linkListIteratorHasNext(itr));
	return itr->currentLink->next->value;
}

void _removeLink(link *lk)
{
	lk->prev->next = lk->next;
	lk->next->prev = lk->prev;
	free(lk);
}

void linkListIteratorRemove(linkListIterator *itr)
{
	assert(!linkListDequeIsEmpty(itr->list));
	_removeLink(itr->currentLink);
}


