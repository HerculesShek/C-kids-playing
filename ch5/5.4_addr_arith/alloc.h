#ifndef ALLOC_H
#define ALLOC_H
#define ul unsigned long

char *alloc(int n);
void afree(char *p);
void str_copy(char *, char *);
void print_alloc_info(void);
ul str_len(char *s);

#endif

