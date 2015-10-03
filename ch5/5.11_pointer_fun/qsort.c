#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // 待排序最大行数
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void quicksort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
  int nlines; //输入行数目
  int numeric = 0; // 是否进行数值排序

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    quicksort((void**) lineptr, 0, nlines-1,
          (int (*)(void*,void*))(numeric ? numcmp : strcmp));
    printf("==========\n");
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big so sort\n");
    return 1;
  }
}

#define MAXLEN 1000
int get_line(char *s, int limit);
char *alloc(int);

int readlines(char *lineprt[], int maxline)
{
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0) {
    // printf("%d\n", len);
    // printf("%s\n", line);
    if (nlines >= maxline || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      // printf("%s\n", p);
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  for (int i = 0; i < nlines; ++i)
    printf("%s\n", lineptr[i]);
}

int get_line(char *s, int limit)
{
  int c, i;
  for(i=0; i<limit-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if(c == '\n'){
    s[i] = (char)c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void quicksort(void *lineptr[], int left, int right,
           int (* comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);
  if (left >= right)
    return;
  swap(lineptr, left, (left + right) / 2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if ((*comp)(lineptr[i], lineptr[left]) < 0)
      swap(lineptr, ++last, i);
  swap(lineptr, left, last);
  quicksort(lineptr, left, last-1, comp);
  quicksort(lineptr, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
  void *temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


#define ALLOCSIZE 5000*1000
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

void print_alloc_info()
{
  printf("allocp index is %ld\n", allocp - allocbuf);
}

#include <stdlib.h> // for atof
/* numcmp:  compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}
