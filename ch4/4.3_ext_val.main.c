#include <stdio.h>
#include <stdlib.h> // for atof 

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

// Reverse Polish
int main()
{
  // printf("%g\n", atof("-.78"));
  // return 0;
  int type;
  double op2;    // second operator 
  char s[MAXOP]; // sotre a operand or operator
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push((int)pop() % (int)op2);
      else
        printf("error: zero modular\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    } 
  }
  return 0;
}

// ============ stack ===============
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
    return val[--sp];
  } else {
    printf("stack empty\n");
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


#include <ctype.h> // for isdigit

int getch(void);
void ungetch(int);

/* getop:  get next character or numeric operand */
int getop(char s[])
{
  int i, c, d;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  // 这个if是加了符号判断之后 修改的 目前来看 代码稍显丑陋 和 下文衔接不够好
  if (!isdigit(c) && c != '.') { 
    if (c == '-' || c == '+') { /* maybe a sign - or + */
      d = getch();
      ungetch(d);
      if (!isdigit(d))      /* not a number */
        return c;
    } else
      return c;
  }
  i = 0;
  if (isdigit(c) || c == '-' || c == '+')    /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')      /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */
int getch(void)  /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)   /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
