#ifndef link_list_queue_h
#define link_list_queue_h 1

#ifndef TYPE
#define TYPE int
#endif

typedef struct link link;
typedef struct linkListQueue linkListQueue;

void linkListQueueInit(linkListQueue *q);
void linkListQueueAddBack(linkListQueue *q, TYPE d);
TYPE linkListQueueFront(linkListQueue *q);
void linkListQueueRemoveFront(linkListQueue *q);
int linkListQueueIsEmpty(linkListQueue *q);

#endif