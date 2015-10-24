#include <stdio.h>
#include <stdlib.h>
// #include "calc.h"
#include "stack.h"
#define MAXVAL 100 // max deepth
int sp = 0; // next idle stack postion
double val[MAXVAL]; // value stack

void push(double f)
{
  printf("push %g\n", f);
  if (sp < MAXVAL)
    val[sp++] = f;
  else {
    printf("error: stack full, can't push %g\n", f);
    exit(-1);
  }
}

double pop(void)
{
  if (sp > 0) {
    double top = val[--sp];
    printf("pop %g\n", top);
    return top;
  } else {
    printf("stack empty pop 0.0\n");
    return 0.0;
  }
}

double peek(void) // 只看不取
{
  if (sp > 0) {
    return val[sp-1];
  } else {
    printf("stack empty\n");
    return 0.0;
  }
}

void repush(void) // 复制栈顶元素
{
  push(peek());
}

void swaptop(void) // 交换栈顶2个元素的值
{
  void swap(double a[], int i, int j);
  if (sp > 1)
    swap(val, sp-1, sp-2);
}

void swap(double a[], int i, int j)
{
  double t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void clear()
{
  sp = 0;
}
// ----------- stack ---------------


