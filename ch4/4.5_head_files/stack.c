#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 // max deepth
int sp = 0; // next idle stack postion
double val[MAXVAL]; // value stack

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("stack empty\n");
    return 0.0;
  }
}

