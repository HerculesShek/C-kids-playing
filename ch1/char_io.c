#include <stdio.h>

void char_io_01()
{
  int c;
  c = getchar();
  while(c != EOF){
    putchar(c);
    c = getchar();
  }
}

void char_io_02()
{
  int c;
  while((c = getchar()) != EOF){
    putchar(c);
  }
}
// exercise 
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

void char_num()
{
  long nc;
  nc = 0;
  while(getchar() != EOF)
    ++nc;
  printf("nc is %d\n", nc);
}

void char_num_2()
{
  double nc;
  for(nc = 0; getchar() != EOF; ++nc)
    ;
  printf("nc is %.0f\n", nc);
}

void line_num()
{
  int c, nl;
  nl = 0;
  while((c = getchar()) != EOF)
    if(c == '\n')
      ++nl;
  printf("line num is %d\n", nl);
}

// exercise 
#define NO_SPACE 0
#define IN_SPACE 1
void copy_space_compress()
{
  int c, state;
  state = NO_SPACE;
  while((c = getchar()) != EOF) {
    if(c == ' '){
      if(NO_SPACE == state){
        state = IN_SPACE;
        continue;
      }
    } else {
      if(IN_SPACE == state){
        state = NO_SPACE;
        printf(" ");
      } 
      putchar(c);
    }
  }
}

main()
{
  // char_io_01();
  // char_io_02();
  char_io_03();
  // char_num();
  // char_num_2();
  // line_num();
  // copy_space_compress();
}
