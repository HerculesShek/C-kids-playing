#include <stdio.h>
#include <limits.h>

int atoi(const char *a);
int lower(const int c);

int main()
{
  long a = -1L;
  unsigned int b = 1U;
  int flag = a < b;
  printf("res is %d\n", flag); // 1

  unsigned long c = 1UL;
  flag = a < c;
  printf("flag is %d\n", flag); // 0

  const char *score = "3389";
  int int_s = atoi(score);
  printf("score is %d\n", int_s);


  char a_u = 'X';
  char a_l = lower(a_u);
  printf("a_l is %c\n", a_l);

  double m = 12837491273948719273948719234.192837491729348719278394;
  //         12837491192341331248123215872.000000
  float f = m;
  printf("f is %f\n", f); // 12837491192341331248123215872.000000
  
  return 0;
}


int lower(const int c)
{
  if ('A' <= c && c <= 'Z') {
    return c-'A'+'a';
  }
  return c;
}

int atoi(const char *a)
{
  int i, n;
  n = 0;
  for (i=0; '0' <= a[i] && a[i] <= '9'; i++) {
    n = 10*n + (a[i]-'0');
  }
  return n;
}
