#include <stdio.h>

int main()
{
  int *pa;
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  // array name can be used as a pointer
  printf("arr[5] = %d\n", *(arr+5));

  // array address = first element address of it 
  pa = &arr[0];
  printf("first element address of arr is %p\n", pa);
  pa = arr;
  printf("address of arr is %p\n", pa);

  // pointer cal
  printf("arr[5] = %d\n", *(pa+5));
  pa = &arr[5];
  printf("arr[3] = %d\n", *(pa-2));

  // pointer can be used as array
  pa = &arr[0];
  printf("arr[8] = %d\n", pa[8]);
  
  return 0;
}
