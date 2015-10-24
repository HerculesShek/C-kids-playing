#include <stdio.h>
#include <stdlib.h> // for atof
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
// #define NUMBER '0' /* signal that a number was found */
#define PI 3.14159265
typedef enum {NUMBER=1024, SIN, COS, EXP, POW, ADD, SUB, MUL, DIV, MOD, UNKNOWN, END, RET} opr;

int getop(char []);
void push(double);
double pop(void);

// Reverse Polish
int main()
{
  // printf("%g\n", sin(270 * PI / 180));
  // return 0;
  
  opr type;
  double op2;    // second operator 
  char s[MAXOP]; // sotre a operand or operator
  while ((type = getop(s)) != END) {
    printf("type is %d\n", type);
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case ADD:
      push(pop() + pop());
      break;
    case MUL:
      push(pop() * pop());
      break;
    case SUB:
      op2 = pop();
      push(pop() - op2);
      break;
    case DIV:
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case MOD:
      op2 = pop();
      if (op2 != 0.0)
        push((int)pop() % (int)op2);
      else
        printf("error: zero modular\n");
      break;
    case SIN:
      push(sin(pop() * PI / 180.0));
      break;
    case EXP:
      push(exp(pop()));
      break;
    case POW:
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case COS:
      push(cos(pop()));
      break;
    case RET:
      printf("\t%.8g\n", pop());
      break;
    case UNKNOWN:
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
  "pow",
  "cos"
};
int num_opers = sizeof(opers) / sizeof(opers[0]);
char *operator; // 如果是惨做函数 sin exp 则指向它
int is_operator(char *op);
opr get_opr(char *op);

/* getop:  get next operator (sin + % lg) or numeric operand */
int getop(char s[])
{
  int i, c, d;
  while ((s[0] = c = getch()) == ' ' || c == '\t') /* remvoe beginning space chars */
    ;
  s[1] = '\0';
  // this following if is ugly
  if (!isdigit(c) && c != '.') {
    if (c == '-' || c == '+') { /* maybe a sign - or + */
      d = getch();
      ungetch(d);
      if (!isdigit(d))  /* not a number but '-' or '+' operator */
        return get_opr(s);
    } else {            /* other operatoer or word  '*' '/' 'x' 'w'... */
      if (c == '/' || c == '*' || c == '%' || c == EOF || c == '\n') /* '/' '*' or '%' */
        return get_opr(s);
      // "xxxsinyyy" xxx and yyy will be ignored 还好没有 math-cos这种函数 否则'-'的处理就十分麻烦了 并且现在 log10 这种函数 还支持不了
      int j = 0;
      while (!isdigit(s[++j]=c=getch()) && c!='.' && c!='+' && c!= '-' && !isspace(c) && c!=EOF && c!='\n')
        ;
      s[j] = '\0';
      ungetch(c);
      printf("len of s if %lu\n", strlen(s));
      printf("s is %s\n", s);

      int op_flag = is_operator(s);
      printf("op_flag is %d\n", op_flag);
      printf("operator is %s\n", operator);
      int k;
      if (op_flag == 0) {
        for (k=strlen(s)-1; k>=op_flag+strlen(operator); k--)
          ungetch(s[k]);
        s[k+1] = '\0';
        return get_opr(s);
      } else if (op_flag > 0) {
        for (k=strlen(s)-1; k>=op_flag; k--)
          ungetch(s[k]);
        s[k+1] = '\0';
        return UNKNOWN;
      } else {
        return UNKNOWN;
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
      return p - op;
    }
  }
  return -1;
}

opr get_opr(char *op) // 获取操作数或者是操作符的类型
{
  if (op[0] == EOF) {
    return END;
  } else if (op[0] == '\n') {
    return RET;
  } else if (strcasecmp("+", op) == 0) {
    return ADD;
  } else if (strcasecmp("-", op) == 0) {
    return SUB;
  } else if (strcasecmp("*", op) == 0) {
    return MUL;
  } else if (strcasecmp("/", op) == 0) {
    return DIV;
  } else if (strcasecmp("%", op) == 0) {
    return MOD;
  } else if (strcasecmp("sin", op) == 0) {
    return SIN;
  } else if (strcasecmp("exp", op) == 0) {
    return EXP;
  } else if (strcasecmp("pow", op) == 0) {
    return POW;
  } else if (strcasecmp("cos", op) == 0) {
    return COS;
  } else {
    return UNKNOWN;
  }
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
