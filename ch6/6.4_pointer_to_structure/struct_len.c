#include <stdio.h>

struct foo{
  char c;
  int i;
};

#define foo_len sizeof(struct foo)

int main()
{
  printf("%lu\n", foo_len);
  return 0;
}
