#include <stdio.h>


int main()
{
  int a[3][4];
  for (int i = 0; i<3;i++) {
    for (int j = 0; j<4; j++)
      printf("%p ", &a[i][j]);
    printf("\n%p",&a[i]);
    printf("\n");
  }

  printf("=========================================\n");
  int c[] = {1,2,3};
  int d[] = {4,5};
  int e[] = {6};
  
  int *b[3] = {c,d,e,};
  for (int i = 0; i<3; i++) {
    printf("%p\n", &b[i]);
  }

  // int *f = {3,4,5};
  // printf("%d", *f);

  int g = {42};
  printf("g = %d\n",g);

  printf("========================================\n");
  char *name[] = {"illegal month", "Jan", "Feb"};
  char aname[][15] = {"illegal month", "Jan", "Feb"};

  for (int i=0; i<3; ++i)
    printf("%s\n", name[i]);
  // printf("%c\n", name[0][0]);

  aname[0][0] = 'I';
  for (int i=0; i<3; ++i)
    printf("%s\n", aname[i]);
  return 0;
}
