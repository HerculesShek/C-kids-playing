// before 1.5

#include <stdio.h>

// 最原始的复制文本
void char_io_01()
{
  int c;
  c = getchar();
  while(c != EOF){
    putchar(c);
    c = getchar();
  }
}

// 复制文本精炼的写法
void char_io_02()
{
  int c;
  while((c = getchar()) != EOF){
    putchar(c);
  }
}

// exercise 打印 c != EOF 的值 和 EOF的值
void char_io_03()
{
  int c;
  c = getchar();
  int flag = c != EOF;
  while(flag){
    printf("flag is %d\n", flag);
    putchar(c);
    if(c != 10){ // new line char
      printf("\n");
    }
    c = getchar();
    flag = c != EOF;
  }
  if(c == EOF){
    printf("EOF is %d\n", EOF);
  }
}

// 统计字符数目
void char_num()
{
  long nc;
  nc = 0;
  while(getchar() != EOF)
    ++nc;
  printf("nc is %ld\n", nc);
}

// for的方式统计字符数目
void char_num_2()
{
  double nc;
  for(nc = 0; getchar() != EOF; ++nc)
    ;
  printf("nc is %.0f\n", nc);
}

// 统计行数
void line_num()
{
  int c, nl;
  nl = 0;
  while((c = getchar()) != EOF)
    if(c == '\n')
      ++nl;
  printf("line num is %d\n", nl);
}

// exercise 压缩空格为1个空格
#define NO_SPACE 0
#define IN_SPACE 1
void copy_space_compress()
{
  int c, state;
  state = NO_SPACE;
  while ((c = getchar()) != EOF) {
    //  if (c == ' ' || c == '\t' || c == '\n') { // 处理文件的时候可以使用此写法
    if (c == ' ' || c == '\t') {
      state = IN_SPACE;
    } else {
      if (state == IN_SPACE) {
        state = NO_SPACE;
        printf(" ");
      }
      putchar(c);
    }
  }

}

int main()
{
  // char_io_01();
  // char_io_02();
  // char_io_03();
  // char_num();
  // char_num_2();
  // line_num();
  copy_space_compress();
  return 0;
}
