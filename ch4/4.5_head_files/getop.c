#include <stdio.h> // for atof 
#include <ctype.h>
#include <string.h>
#include "getop.h"
#include "getch.h"

static char *opers[] = {
  "sin",
  "exp",
  "pow",
  "cos",
  "floor",
  "sqrt"
};
static int num_opers = sizeof(opers) / sizeof(opers[0]);

/* getop:  get next character or numeric operand */
opr getop(char s[])
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
      if (!isdigit(d) && d != '.')  /* not a number but '-' or '+' operator */
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
      int op_flag = is_operator(s);
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
  } else if (strcasecmp("floor", op) == 0) {
    return FLOOR;
  } else if (strcasecmp("sqrt", op) == 0) {
    return SQRT;
  } else {
    return UNKNOWN;
  }
}


