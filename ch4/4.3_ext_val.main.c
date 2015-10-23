#include <stdio.h>
#include <stdlib.h> // for atof
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define PI 3.14159265
typedef enum {SIN = 1024, EXP, POW} opr;


int getop(char []);
void push(double);
double pop(void);

// Reverse Polish
int main()
{
  // printf("%g\n", sin(270 * PI / 180));
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

// ====================== getop ============================
#include <ctype.h> // for isdigit
#include <string.h> // for index 

int getch(void);
void ungetch(int);
char *opers[] = {
  "sin",
  "exp",
  "pow"
};
int num_opers = sizeof(opers) / sizeof(opers[0]);
char *operator; // 如果是惨做函数 sin exp 则指向它

/* getop:  get next character or numeric operand */
int getop(char s[])
{
  int i, c, d;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  // 这个if是加了符号判断之后 修改的 目前来看 代码稍显丑陋 并且 和下文衔接不够好
  if (!isdigit(c) && c != '.') {
    if (c == '-' || c == '+') { /* maybe a sign - or + */
      d = getch();
      ungetch(d);
      if (!isdigit(d))  /* not a number but '-' or '+' */
        return c;
    } else {            /* other operatoer or word  '*' '/' 'x' 'w'... */
      if (c == '/' || c == '*' || c == '%') /* '/' '*' or '%' */ 
        return c;
      else { // "xxxsinyyy" xxx and yyy will be ignored 还好没有 math-cos这种函数 否则'-'的处理就十分麻烦了 并且现在 log10 这种函数 还支持不了 TODO
        int j = 0;
        while (!isdigit(s[++j]=c=getch()) && c!='.' && c!='+' && c!= '-' && !isspace(c))
          ;
        s[j] = '\0';
        ungetch(c);

        int op_flag = is_operator(s);
        if (op_flag == 0)
          return operator; // TODO return enum
        else if (op_flag > 0) { // TODO ungetch 
          
        } else { // TODO return enum
          return unknow;
        }
        
      }
    }
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

int is_operator(char *op) // 看字符串op中是否含有 操作函数 比如 sin exp
{
  char *p = NULL;
  for (int i=0; i<num_opers; i++) {
    p = strstr(op, opers[i]);
    if (p) {
      operator = opers[i];
      return p - opers[i];
    }
  }
  return -1;
}

// ---------------------- getop ----------------------------

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
