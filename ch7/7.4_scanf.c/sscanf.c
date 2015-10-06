#include <stdio.h>

int get_line(char s[], int limit);

int main()
{
  int day, month, year;
  char monthname[20];
  char line[1000];
  while (get_line(line, sizeof(line)) > 0) {
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
      printf("valid: %s\n", line); /* 25 Dec 1988 form */
    else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
      printf("valid: %s\n", line); /* mm/dd/yy form */
    else
      printf("invalid: %s\n", line); /* invalid form */
  }
  return 0;
}

int get_line(char s[], int limit)
{
  int c, i;
  for(i=0; i<limit-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if(c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
