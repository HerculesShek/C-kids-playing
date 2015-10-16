#include <stdio.h>

enum mon {A=1, B, C};
enum foo {D=1, E, F};
typedef enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN } weekday;
// typedef enum { MON=1, TUE, WED, THU, FRI, SAT, SUN } weekday2;


enum mon m0; 
int main()
{
  enum mon m;
  printf("m is %d\n", m0); // 0
  printf("m is %d\n", m);  // undefined

  enum mon a = F;
  printf("a is %d\n", a);

  weekday day = WED;
  printf("day is %d\n", day);
  return 0;
}
