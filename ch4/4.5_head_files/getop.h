#ifndef _GETOP_H
#define _GETOP_H

typedef enum {NUMBER=1024, SIN, COS, EXP, POW, FLOOR, SQRT, ADD, SUB, MUL, DIV, MOD, UNKNOWN, END, RET} opr;

char *operator; // 如果是库函数 如 sin exp 则指向它
int is_operator(char *op);
opr get_opr(char *op);

/* getop:  get next operator (sin + % lg) or numeric operand */
opr getop(char s[]);

#endif // _GETOP_H
