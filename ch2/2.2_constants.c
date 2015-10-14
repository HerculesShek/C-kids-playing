#include <stdio.h>

#define len 10

int nums[len];
int a;
char chr;

int main()
{
  int c = '0';
  printf("%d\n", c); // 48

  c = '\0';
  printf("%d\n", c); // 0

  c = '\n';
  printf("%d\n", c); // 10
  c = 'A';
  printf("%d\n", c); // 65

  c = '\12';
  printf("%d\n", c); // 10
  c = '\xa';
  printf("%d\n", c); // 10
  printf("%c", c); // '\n'


  c = '\101';
  printf("%c\n", c); // A
  c = '\x41';
  printf("%c\n", c); // A

  printf("==========================\n");
  for (int i=0; i<len; ++i)
    printf("%d, ", nums[i]);
  printf("\n");
  printf("a is %d\n", a);
  printf("chr is %c\n", chr);
  printf("chr is %d\n", chr);
  
  return 0;
}
