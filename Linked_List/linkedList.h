#ifndef __Linked_LIST_H__
#define __Linked_LIST_H__

#define FALSE   0
#define TRUE    1 

typedef int LData;

typedef struct _node {
    LData data;
    struct _node * next;
} Node;

typedef struct _linkedList {
    Node * head;    // 연결리스트의 시작(더미노드)
    Node * tail;
    Node * cur;     // 참조와 삭제를 위한 포인터 변수
    Node * before;  // 삭제를 돕는 포인터 변수
    int numOfData;
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata); // 연결리스트의 시작을 찾아서 pdata가 가리키는 곳에 데이터를 넣는다.
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif