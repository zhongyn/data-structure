#include "linkListStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct link
{
	TYPE value;
	struct link *next;
	struct link *prev;
};

struct linkListQueue
{
	struct link *firstLink;
	struct link *lastLink;
};

void linkListDequeInit(linkListDeque *q)
{
	link *front = malloc(sizeof(link));
	link *back = malloc(sizeof(link));
	assert(front != 0);
	assert(back != 0);
	front->next = back;
	back->prev = front;
	front->prev = 0;
	back->next = 0;
}

void _addBefore(link *lk, TYPE d)
{
	link *newLink = malloc(sizeof(link));
	assert(newLink != 0);
	newLink->value = d;
	newLink->next = lk;
	newLink->prev = lk->prev;
	lk->prev->next = newLink;
	lk->prev = newLink;
}

void linkListDequeAddBack(linkListDeque *q, TYPE d)
{
	_addBefore(q->back, d);
}

void linkListDequeAddFront(linkListDeque *q, TYPE d)
{
	_addBefore(q->front->next, d);
}

void _removeLink(link *lk)
{
	lk->prev->next = lk->next;
	lk->next->prev = lk->prev;
	free(lk);
}

void linkListDequeRemoveFront(linkListDeque *q)
{
	assert(!linkListDequeIsEmpty(q));
	_removeLink(q->front->next);
}

void linkListDequeRemoveBack(linkListDeque *q)
{
	assert(!linkListDequeIsEmpty(q));
	_removeLink(q->back->prev);
}

int linkListDequeIsEmpty(linkListDeque *q)
{
	return q->front->next->next;
}

