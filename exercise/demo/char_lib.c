// lib file about char processing

#include <stdio.h>
#include <ctype.h>

// 获取输入中的一行 line的长度最大为limit 但是最后一位永远是'\0' 所以
// line的最大有效长度是 limit-1
int get_line(char *line, int limit)
{
  int c, i;
  for (i=0; i<limit-1 && (c=getchar()) != EOF && c != '\n'; i++) 
    line[i] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

// 返回pattern在line中首次出现的位置 0,1,2... 或 -1 
int strindex(char *line, char *pattern)
{
  int i, j, k;
  for (i=0; line[i] != '\0'; i++) {
    for (j=i, k=0; pattern[k] != '\0' && pattern[k++]==line[j++];)
      ;
    if (k>0 && pattern[k] == '\0')
      return i;
  }
  return -1;
}

// convert string to double 
double atof(const char *s)
{
  double val, power;
  int i, sign;
  for (i=0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (val=0.0; isdigit(s[i]); i++)
    val = 10.0*val+(s[i]-'0');
  if (s[i] == '.')
    i++;
  for (double j=10.0; isdigit(s[i]); j*=10.0, i++)
    val += (s[i]-'0') / j;
  return sign*val;
}

