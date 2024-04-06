#include <stdlib.h>
#include "queue.h"

void QueueInit(Queue * pq) 
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq) 
{
    if (pq->front == NULL)
        return TRUE;
    return FASLE;
}

void Enqueue(Queue * pq, Data data) 
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (pq->front == NULL)
        pq->front = newNode;
    else
        pq->rear->next = newNode;
    newNode->next = NULL;
    pq->rear = newNode;
}

Data Dequeue(Queue * pq) 
{
    Node * rpos = pq->front;
    Data data = rpos->data;
    pq->front = pq->front->next;
    free(rpos);
    return data;
}

Data QPeek(Queue * pq) 
{
    if (pq->front != NULL)
        return pq->front->data;
    else
        return -1;
}