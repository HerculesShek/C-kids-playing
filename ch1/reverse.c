#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int limit);
void reverse(char to[], char from[], int len);
void test_rev(char from[]);

int main()
{
  int len;
  char line[MAXLINE];
  
  while((len = get_line(line, MAXLINE)) > 0)
    test_rev(line);
  return 0;
}


void test_rev(char from[])
{
  int len = 0;
  while(from[len] != '\0')
    ++len;
  char to[len+1];
  reverse(to, from, len);
  printf("%s\n", to);
}

void reverse(char to[], char from[], int len)
{
  for(int i=0; i<len; ++i)
    to[i] = from[len-i-1];
  to[len] = '\0';
}


int get_line(char s[], int limit)
{
  int c, i;
  for(i=0; i<limit-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  /*
  if(c == '\n'){
    s[i] = c;
    ++i;
  } 
  */
  s[i] = '\0';
  return i;
}
