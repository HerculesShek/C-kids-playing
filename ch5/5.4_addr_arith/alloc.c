#include <stdio.h>
#include "alloc.h"
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];

static char *allocp = allocbuf;

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

void str_copy(char *org, char *dest)
{
  while (*dest++ = *org++)
    ;
}

void print_alloc_info()
{
  printf("allocp index is %ld\n", allocp - allocbuf);
}

ul str_len(char *s)
{
  ul n;
  for (n = 1; *s != '\0'; s++, n++)
    ;
  return n;
}


