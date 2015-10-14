#include <stdio.h>
// 获取输入的所有行 将长度最大的打印出来
#define MAXLINE 1000

int max;				// 最大长度
char line[MAXLINE];		// 当前输入行
char longest[MAXLINE]; 	// 最长的行

int get_line(void);
void copy(void);

int main()
{
  int len;
  // extern int max;
  // extern char longest[];

  max = 0;
  while ((len = get_line()) > 0)
  	if (len > max) {
  		max = len;
  		copy();
  	}
  if (max>0)
  	printf("%s", longest);
  return 0;
}

int get_line(void)
{
	int c, i;
	// extern char line[];
	for (i=0; i<MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copy(void)
{
	int i = 0;
	// extern char line[], longest[];
	while ((longest[i] = line[i]) != '\0')
		++i;
}
