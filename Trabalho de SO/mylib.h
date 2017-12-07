#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>

#define MAX_CMD_LEN 2048
#define MAX_ARGS 1024

int run (char *, int *);
int pipeline(FILE *fpin, FILE *fpout, const char *cmd1, const char *cmd2, ...);

#endif /* MYLIB_H */
