#include <stdio.h>


int main()
{
  int a = 42;
  int *ip = &a;
  
  printf("ip address is %p\n", ip);

  return 0;
}
