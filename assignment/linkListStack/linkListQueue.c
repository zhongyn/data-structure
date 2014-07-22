#include "linkListStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct link
{
	TYPE value;
	struct link *next;
};

struct linkListQueue
{
	struct link *firstLink;
	struct link *lastLink;
};


void linkListQueueInit(linkListQueue *q)
{
	link *base = (link*)malloc(sizeof(link));
	assert(base != 0);
	base->next = 0;
	q->firstLink = q->lastLink = base;
}

void linkListQueueAddBack(linkListQueue *q, TYPE d)
{
	link *newLink = (link*)malloc(sizeof(link));
	assert(newLink != 0);
	newLink->value = d;
	newLink->next = 0;
	q->lastLink->next = newLink;
	q->lastLink = newLink;
}

TYPE linkListQueueFront(linkListQueue *q)
{
	assert(!linkListQueueIsEmpty(q));
	return q->firstLink->next->value;
}

void linkListQueueRemoveFront(linkListQueue *q)
{
	assert(!linkListQueueIsEmpty(q));
	link *tem = q->firstLink;
	q->firstLink->next = tem->next;
	free(tem);
}

int linkListQueueIsEmpty(linkListQueue *q)
{
	return q->firstLink->next;
}
