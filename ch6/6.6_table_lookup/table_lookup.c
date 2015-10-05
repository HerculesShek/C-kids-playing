#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];  /* pointer table */
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *strdup(const char *);

int main()
{
  char *name = "IN";
  char *defn = "1";

  struct nlist *item = install(name, defn);
  struct nlist *look = lookup(name);
  if (item == look)
    printf("ok\n");
  return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

/* lookup:  look for s in hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;
  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;     /* found */
  return NULL;       /* not found */
}


/* install:  put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;
  
  if ((np = lookup(name)) == NULL) { /* not found */
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    // 这里是有技巧的 找不到有2种情况 hashtab[hashval]为空或者不为空
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else       /* already there */
    free((void *) np->defn);   /*free previous defn */
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

char *strdup(const char *s) {
  char *d = malloc(strlen(s) + 1);   // Allocate memory
  if (d != NULL) strcpy(d, s);         // Copy string if okay
  return d;
}
