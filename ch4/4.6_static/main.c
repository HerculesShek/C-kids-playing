#include <stdio.h>
#include "foo.h"

int main()
{
  for (int i = 0; i < 10; ++i)
    printf("invoke foo %d times\n", foo());
  return 0;
}
