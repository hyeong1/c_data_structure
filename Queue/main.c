#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    printf("큐 생성\n");
    QueueInit(&q);

    if (QIsEmpty(&q))
        printf("큐가 비어있음\n");

    printf("큐에 데이터 삽입\n");
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 5);
    Enqueue(&q, 7);
    Enqueue(&q, 3);

    printf("큐 deque\n");
    while (!QIsEmpty(&q))
    {
        if (QPeek(&q) != -1)
            printf("front data = %d\n", QPeek(&q));
        printf("%d dequeue\n", Dequeue(&q));
    }
    
    return 0;
}