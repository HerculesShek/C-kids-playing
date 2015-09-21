#include <stdio.h>

#define IN  1
#define OUT 0

void status()
{
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while((c = getchar()) != EOF){
    ++nc;
    if('\n' == c)
      ++nl;
    if(' ' == c || '\n' == c || '\t' == c){
      state = OUT;
    } else if(state == OUT){
      state = IN;
      ++nw;
    }
  }
  printf("nc:%d\tnw:%d\tnl:%d\n", nc, nw, nl);
}

main()
{
  status();
}
