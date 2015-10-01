#include <stdio.h>

void strcopy(char *, char *);
int strcmp(char *, char *);

int main()
{
  char amessage[] = "now is the time";
  char *pmessage = "now is the time";

  char *a = "aabb";
  char *b = "aacc";
  int res = strcmp(a, b);
  printf("%d\n", res);
  return 0;
}

void strcopy(char *dest, char *org)
{
  while (*dest++ = *org++)
    ;
}

int strcmp_1(char *s, char *t)
{
  int i;
  for (i = 0; s[i] == t[i]; ++i)
    if (s[i] == '0')
      return 0;
  return s[i] - t[i];
}

int strcmp(char *s, char *t)
{
  for (; *s == *t; s++, t++)
    if (*s == '0')
      return 0;
  return *s - *t;
}

