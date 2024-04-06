#include <stdio.h>

void fun(int arr[]) // 매개변수는 arr의 첫 번째 요소에 대한 포인터
{
  int i;
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  for (i = 0; i < arr_size; i++)
      printf("%d ", arr[i]);
}
 
int main()
{
  int i;
  int arr[4] = {10, 20 ,30, 40};
  fun(arr);
  return 0;
} 