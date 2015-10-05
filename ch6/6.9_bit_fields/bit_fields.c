#include <stdio.h>

typedef struct {
  unsigned int is_keyword : 1;
  unsigned int is_extern  : 1;
  unsigned int is_static  : 1;
} flags;

int main()
{
  flags f = {1,0,1};
  flags *p = &f;
  printf("is_keyword: %d\n", (*p).is_keyword);
  printf("is_extern: %d\n", (*p).is_extern);
  printf("is_static: %d\n", (*p).is_static);
  
  return 0;
}
