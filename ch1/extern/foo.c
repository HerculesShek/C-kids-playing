#include <stdio.h>
#include "foo.h"

int main()
{
  extern char *loc;
  extern char *country;
  age = 26;
  printf("name is %s age = %d loc is %s of %s\n", name, age, loc, country);
  return 0;
}

char *country = "American";
