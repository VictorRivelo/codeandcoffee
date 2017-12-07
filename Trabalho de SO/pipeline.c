#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include "mylib.h"

#include <stdio.h>
#include <stdlib.h>


/* infelizmente, nao conseguimos desenvolver a funcao de pipeline, mas a inserimos no projeto
para demonstrar que entendemos o processo de inclusão na biblioteca e uso pelo teste.c */
int pipeline(FILE *fpin, FILE *fpout, const char *cmd1, const char *cmd2, ...){
	return 0;
}
