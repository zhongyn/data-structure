#ifndef link_list_deque_h
#define link_list_deque_h 1

#ifndef TYPE
#define TYPE int
#endif

typedef struct link link;
typedef struct linkListDeque linkListDeque;

void linkListDequeInit(linkListDeque *q);
void linkListDequeAddBack(linkListDeque *q, TYPE d);
void linkListDequeAddFront(linkListDeque *q, TYPE d);
void linkListDequeRemoveFront(linkListDeque *q);
void linkListDequeRemoveBack(linkListDeque *q);
int linkListDequeIsEmpty(linkListDeque *q);

#endif