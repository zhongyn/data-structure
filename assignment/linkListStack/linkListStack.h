#ifndef link_list_stack_h
#define link_list_stack_h 1

#ifndef TYPE
#define TYPE int
#endif

typedef struct link link;
typedef struct linkListStack linkListStack;

void linkListStackInit(linkListStack *s);
void linkListStackFree(linkListStack *s);
void linkListStackPush(linkListStack *s, TYPE d);
TYPE linkListStackTop(linkListStack *s);
void linkListStackPop(linkListStack *s);
int linkListStackIsEmpty(linkListStack *s);

#endif