#include <stdio.h>

#define MAXLINE 1000


int main()
{
  int c;
  while((c=getchar()) != EOF){
    if(c == '\t')
      printf("    ");
    else
      putchar(c);
  }
}

