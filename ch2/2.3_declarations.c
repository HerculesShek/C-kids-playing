#include <stdio.h>

int foo(int);

// int score = foo(33); // com err
int c = 32+7; // OK 
const int f; // 0
int main()
{
  int a = 4;
  int b = foo(a);
  const int d; // undefined 
  printf("%d\t%d\t%d\t%d\n", a, b, d, f);

  const double e = 2.718281828;
  const char msg[] = "I have a dream;";
  
}

int foo(int a)
{
  return a*a;
}
