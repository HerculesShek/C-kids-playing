#include <stdio.h>
#include "alloc.h"

int main()
{
  char *name = "xingzhe";
  char *name_new = alloc(8);

  str_copy(name, name_new);
  printf("new name is \"%s\"\n", name_new);
  print_alloc_info();
  return 0;
}
