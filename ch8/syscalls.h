#ifndef SYSCALLS_H
#define SYSCALLS_H

#define BUFSIZE 1024
int read(int fd, char *buf, int n);
int write(int fd, char *buf, int n);

#endif
