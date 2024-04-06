#ifndef __QUEUE_H__
#define __QUEUE_H__

#define FASLE   0
#define TRUE    1

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
} Node;


typedef struct _queue
{
    Node * front;
    Node * rear;   
} Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif