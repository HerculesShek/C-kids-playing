#include <stdio.h>

int main()
{
  int a, b, c;
  a = (b=3,c=4);
  printf("a=%d, b=%d, c=%d\n", a, b, c); // a=3, b=3, c=4

  
  return 0;
}
