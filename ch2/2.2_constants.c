#include <stdio.h>

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

  
  
  return 0;
}
