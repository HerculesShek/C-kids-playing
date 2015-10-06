#include <fcntl.h>

// 此文件仅作展示 没法编译

int main()
{
  int fd;
  int open(char *name, int flags, int perms);
  fd = open(name, flags, perms);
  return 0;
}
