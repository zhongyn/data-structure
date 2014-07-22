#include "linkListStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct link
{
	TYPE value;
	struct link *next;
};

struct linkListStack
{
	struct link *firstLink;
};

void linkListStackInit(linkListStack *s)
{
	s->firstLink = 0;
}

void linkListStackFree(linkListStack *s)
{
	while(!linkListStackIsEmpty(s))
		linkListStackPop(s);
}

void linkListStackPush(linkListStack *s, TYPE d)
{
	link *newLink = (link*)malloc(sizeof(link));
	assert(newLink != 0);
	s->firstLink = newLink;
	newLink->value = d;
	newLink->next = 0;
}

TYPE linkListStackTop(linkListStack *s)
{
	assert(!linkListStackIsEmpty(s));
	link *top = s->firstLink;
	return top->value;
}

void linkListStackPop(linkListStack *s)
{
	assert(!linkListStackIsEmpty(s));
	link *tem = s->firstLink;
	s->firstLink = tem->next;
	free(tem);
}

int linkListStackIsEmpty(linkListStack *s)
{
	return (s->firstLink == 0);
}
