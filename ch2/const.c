#include <stdio.h>

int main()
{
  const char *name = "xingzhe";
  char name2[] = "jack";

  // *name = 'X';
  *name2 = 'J';

  printf("name is %s\n", name);
  printf("name2 is %s\n", name2);
  
  return 0;
}
