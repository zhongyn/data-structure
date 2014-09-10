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
	if (itr->currentLink->next != itr->list->lastlink)
	{
		itr->currentLink = itr->currentLink->next;
		return 1;
	}
	return 0;
}

TYPE linkListIteratorNext(linkListIterator *itr)
{
	return itr->currentLink->value;
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
	link *tem = itr->currentLink;
	itr->currentLink = tem->prev;
	_removeLink(itr->currentLink);
}


