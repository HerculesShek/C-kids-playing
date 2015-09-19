#include <stdio.h>
void printf_demo()
{
  int a = 123456;
  // printf("%d\n", a);
  // printf("%8d\n", a);

  int b = 9;
  // printf("%o\n", b);

  b = 17;
  // printf("%x\n", b);

  b = 97;
  // printf("%c\n", b);

  b = 9700;
  // printf("%c\n", b);
  
  b = 97;
  printf("%s\n", "hello");
  
}

main()
{
  printf_demo();
}
