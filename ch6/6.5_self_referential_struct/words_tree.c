#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;
  struct tnode *talloc(void);
  // TODO 这里忽略了对strdup和talloc的错误检查
  if (p == NULL) { // new word
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

void treeprint(struct tnode *p)
{
  if (p == NULL)
    return;
  treeprint(p->left);
  printf("%4d %s\n", p->count, p->word);
  treeprint(p->right);
}

/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;
  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c; }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
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

#include <stdlib.h>
struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
  char *p;
  p = (char *)malloc(strlen(s) + 1);
  if (p != NULL)
    strcp(p, s);
  return p;
}
