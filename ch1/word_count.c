// 1.5.4 统计单词的个数 字符个数 行数
#include <stdio.h>

#define IN  1
#define OUT 0

void status()
{
  int c, state, nc, nw, nl;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if ('\n' == c)
      ++nl;
    if (' ' == c || '\n' == c || '\t' == c) {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("nc:%d\tnw:%d\tnl:%d\n", nc, nw, nl);
}

int main()
{
  status();
  return 0;
}
