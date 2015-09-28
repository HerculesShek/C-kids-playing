#include <stdio.h>
#include <limits.h>

int main()
{
  printf("===========char============\n");
  printf("CHAR_BIT is %d\n", CHAR_BIT);
  printf("%d\n", SCHAR_MAX);
  printf("%d\n", SCHAR_MIN);
  printf("%u\n", UCHAR_MAX);
  // printf("%u\n", UCHAR_MIN);
  
  printf("===========short============\n");
  printf("%d\n", SHRT_MAX);
  printf("%d\n", SHRT_MIN);
  printf("%u\n", USHRT_MAX);
  
  printf("===========int============\n");
  printf("%d\n", INT_MAX);
  printf("%d\n", INT_MIN);
  printf("%u\n", UINT_MAX);
  // printf("%d\n", UINT_MIN);

  printf("===========long============\n");
  printf("LONG_BIT is %d\n", LONG_BIT);
  printf("%ld\n", LONG_MAX);
  printf("%ld\n", LONG_MIN);
  printf("%lu\n", ULONG_MAX);
  
}
