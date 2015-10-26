#include <stdio.h>
#include <string.h>

int main()
{
  int c;
  while ((c = getchar())!= EOF) {
    printf("current char is %c\n", c);
  }

  printf("eof is %d\n", c); // -1

  char eof[2];
  eof[0] = EOF;
  eof[1] = '\0';
  printf("eof is %s\n", eof); // 
  printf("len of eof is %lu\n", strlen(eof)); // 1
  
  return 0;
}
