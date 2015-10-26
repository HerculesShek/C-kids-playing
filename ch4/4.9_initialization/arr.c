#include <stdio.h>

int main()
{
  int a[8] = {1,2,3};
  for (int i = 0; i < 8; ++i)
    printf("%d ", a[i]);
  printf("\n");

  int c[3] = {1,2,3,4,5};
  for (int i = 0; i < 3; ++i)
    printf("%d ", c[i]);
  printf("\n");
  return 0;
}
