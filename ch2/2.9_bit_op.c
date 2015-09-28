#include <stdio.h>

int main()
{
  int a = 3, b = 5;
  a ^= b;
  b ^= a;
  a ^= b;
  printf("%d %d\n", a, b);

  b >>= 0;
  printf("%d %d\n", a, b);

  a = a&~(1<<2);
  printf("%d %d\n", a, b);

  
  a = a|(1<<2);
  printf("%d %d\n", a, b);
  
  int min = -1;
  a = min<<3|min>>29;
  printf("%d %d\n", a, b);

  int seven = ~(~0<<3);
  printf("%d\n", seven);

  int org = 21;
  int n = 3;
  int pos = 4;
  int five = (org>>(1+pos-n)) & ~(~0<<n);
  printf("%d\n", five);
}
