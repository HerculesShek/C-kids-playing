#include <stdio.h>
#include <string.h>
#define len 10

int nums[len];
int a;
char chr;

enum mon {A=3, B, C, D=4, E};
// enum jac {A, B} /* wrong: redefinition of enumerator */

enum color {RED, BLUE, GREEN};
typedef enum {NO, YES} boole;

int main()
{
  int c = '0';
  printf("%d\n", c); // 48

  c = '\0';
  printf("%d\n", c); // 0

  c = '\n';
  printf("%d\n", c); // 10
  c = 'A';
  printf("%d\n", c); // 65

  c = '\12';
  printf("%d\n", c); // 10
  c = '\xa';
  printf("%d\n", c); // 10
  printf("%c", c); // '\n'


  c = '\101';
  printf("%c\n", c); // A
  c = '\x41';
  printf("%c\n", c); // A

  printf("==========================\n");
  for (int i=0; i<len; ++i)
    printf("%d, ", nums[i]);
  printf("\n");
  printf("a is %d\n", a);
  printf("chr is %c\n", chr);
  printf("chr is %d\n", chr);

  int l = strlen("hello");
  printf("l is %d\n", l);

  printf("A = %d\n", A);
  printf("B = %d\n", B);
  printf("C = %d\n", C);
  printf("D = %d\n", D);
  printf("E = %d\n", E);

  printf("====================\n");
  enum color clr = 9;
  printf("clr = %d\n", clr);

  enum color {RED, BLUE, GREEN} ccc = 8;
  printf("ccc = %d\n", ccc);


  boole flag = 3;
  printf("flag = %d\n", flag);
  return 0;
}
