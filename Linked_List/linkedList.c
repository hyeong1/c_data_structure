#include <stdlib.h>
#include "linkedList.h"

// 연결리스트 초기화
void ListInit(List * plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL; // 초기 생성 -> 다음 노드 없음
    plist->tail = NULL;
    plist->numOfData = 0; // 저장된 데이터의 수
}

// 연결리스트에 노드 삽입 -뒤에 삽입
void LInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node)); // 삽입할 새 노드 생성
    newNode->data = data;
    if (plist->head->next == NULL) // 초기 상태면
        plist->head->next = newNode;
    else
        plist->tail->next = newNode;
    newNode->next = NULL; 
    plist->tail = newNode;
    (plist->numOfData)++;              // 현재까지 저장한 데이터의 수 증가
}

// 연결리스트에 노드 삽입 -헤드 뒤에 삽입
// void LInsert(List * plist, LData data)
// {
//     Node * newNode = (Node*)malloc(sizeof(Node)); // 삽입할 새 노드 생성
//     newNode->data = data;
//     newNode->next = plist->head->next;
//     plist->head->next = newNode;
//     (plist->numOfData)++;              // 현재까지 저장한 데이터의 수 증가
// }

// 연결리스트의 head 참조
int LFirst(List * plist, LData * pdata)
{
    if (plist->head->next == NULL) // 연결리스트에 노드 없음
        return FALSE;
    
    plist->before = plist->head;    // before은 더미노드(head)를 가리킴
    plist->cur = plist->head->next; // cur은 시작 노드(head 다음노드)

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List * plist, LData * pdata)
{
    if (plist->cur->next == NULL) // 현재 노드의 next가 NULL이면 tail 노드
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List * plist) 
{
    Node * rpos = plist->cur;
    LData rdata = rpos->data;

    // 삭제할 노드의 이전 노드 next를 삭제할 노드의 next로 설정
    plist->before->next = rpos->next;
    plist->cur = plist->before; // 현재 가리키는 포인터를 삭제할 노드 이전 노드로 재설정

    free(rpos);
    (plist->numOfData)--;
    return rdata; // 삭제한 데이터 반환
}

int LCount(List * plist) 
{
    return plist->numOfData;
}