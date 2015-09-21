#include <stdio.h>

main()
{
  int c, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for(int i = 0; i<10; ++i) 
    ndigit[i] = 0;

  while((c =getchar()) != EOF){
    if('0' <= c && c <= '9')
      ++ndigit[c-'0'];
    else if(c == ' ' || c == '\t' || c == '\n')
      ++nwhite;
    else
      ++nother;
  }

  printf("digits =");
  for(int i = 0; i<10; ++i)
    printf(" %d", ndigit[i]);
  printf(", nwhite = %d, nother = %d\n", nwhite, nother);
}
