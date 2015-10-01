#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
  // int r = strcmp("cffff", "bb");
  // printf("%d\n", r);
  int nlines; //输入行数目
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines-1);
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

void qsort(char *lineptr[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);
  if (left >= right)
    return;
  swap(lineptr, left, (left + right) / 2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if (strcmp(lineptr[i], lineptr[left]) < 0)
      swap(lineptr, ++last, i);
  swap(lineptr, left, last);
  qsort(lineptr, left, last-1);
  qsort(lineptr, last+1, right);
}

void swap(char *v[], int i, int j)
{
  char *temp = v[i];
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
