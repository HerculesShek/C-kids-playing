#include <stdio.h>

union u_tag {
  int ival;
  short s;
  float fval;
  char *sval;
};
typedef enum {INT, FLOAT, STRING} type;

// 联合嵌套在结构中 反之亦可
#define NSYM 3
struct {
  char *name;
  int flags;
  int utype;
  union {
    int ival;
    float fval;
    char *sval;
  } u;
} symtab[NSYM];

int main()
{
  type utype = INT;
  int a = 42;
  union u_tag u = {44};
  // u.ival = a;
  
  if (utype == INT)
    printf("%d\n", u.ival);
  else if (utype == FLOAT)
    printf("%f\n", u.fval);
  else if (utype == STRING)
    printf("%s\n", u.sval);
  else
    printf("bad type %d in utype\n", utype);

  // 下面说明共享内存 猜测是右侧对其的
  printf("%d\n", u.s);
  u.s = 12;
  printf("%d\n", u.ival);
  return 0;
}
