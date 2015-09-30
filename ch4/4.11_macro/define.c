#include <stdio.h>
#define forever for(;;)
#define square(x) x * x
#define max(A, B) ((A) > (B) ? (A) : (B))
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back

int main()
{
  int i = 0;
  forever {
    printf("go forever\n");
    i++;
    if (i > 10)
      break;
  }

  int a = 5;
  int b = 6;
  int c = max(a++, b++);
  printf("c = %d\n", c); // error

  int d = 4;
  printf("square of (d+1) = %d\n", square(d+1)); // error

#undef square
  int square(int x);
  printf("square of (d+1) = %d\n", square(d+1));

  dprint(3.0/5.0);

  int a1 = 40;
  paste(a, 1)++;
  printf("a1 = %d\n", a1);
  
  return 0;
}

int square(int x)
{
  return x*x;
}
