#include <stdio.h>
#include "linkedList.h"

int main()
{
    List list;
    int data;
    ListInit(&list);

    // 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 33);
    LInsert(&list, 44);
    LInsert(&list, 55);

    // 저장된 데이터 수 출력
    printf("현재까지 저장한 데이터의 수: %d \n", LCount(&list));

    // 저장된 데이터 출력
    if (LFirst(&list, &data))
    {
        printf("%d\n", data);

        while (LNext(&list, &data))
            printf("%d\n", data);
    }
    printf("\n\n");

    // 숫자 33 데이터 삭제
    if (LFirst(&list, &data))
    {
        if (data == 33)
            LRemove(&list);
        
        while (LNext(&list, &data)) {
            if (data == 33)
                LRemove(&list);
        }
    }

    // 삭제 후 저장된 데이터 수 출력
    printf("현재까지 저장한 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d\n", data);

        while (LNext(&list, &data))
            printf("%d\n", data);
    }
    printf("\n\n");

    return 0;
}
