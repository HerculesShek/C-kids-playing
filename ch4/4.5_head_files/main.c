#include <stdio.h>
#include <stdlib.h> // for atof
#include <math.h>
#include "getop.h"
#include "stack.h"

#define MAXOP 100 /* max size of operand or operator */
#define PI 3.14159265

// Reverse Polish
int main()
{
  opr type;
  double op2;    // second operator 
  char s[MAXOP]; // sotre a operand or operator
  while ((type = getop(s)) != END) {
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
    case FLOOR:
      push(floor(pop()));
      break;
    case COS:
      push(cos(pop()));
      break;
    case SQRT:
      push(sqrt(pop()));
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

