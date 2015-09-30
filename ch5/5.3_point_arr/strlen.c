#include <stdio.h>
#define ul unsigned long
ul str_len(char *s);

int main()
{
  ul len = str_len("hello");
  printf("len = %lu\n", len);
  
  return 0;
}

ul str_len(char *s)
{
  printf("%c\n", s[0]);
  ul n;
  for (n = 0; *s != '\0'; s++, n++)
    ;
  return n;
}
