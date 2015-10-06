#include "../syscalls.h"
#include <stdio.h>
#undef getchar



/* getchar:  unbuffered single character input */
int getchar(void)
{
  char c;
  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
