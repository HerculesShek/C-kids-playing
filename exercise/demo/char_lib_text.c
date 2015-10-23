#include <stdio.h>
#include "char_lib.h"
#define MAXLINE 25

char line[MAXLINE];
int main()
{
  int len, index;
  char *pattern = "xingzhe";
  while ((len = get_line(line, MAXLINE)) > 0) {
    printf("len is %d\n", len);
    printf("line is %s\n", line);
    index = strindex(line, pattern);
    if (index >= 0) {
      printf("index is %d\n", index);
    }
    double d = atof(line);
    printf("line is numberic %f\n", d);
  }
  
  return 0;
}
