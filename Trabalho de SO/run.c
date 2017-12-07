#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int run (char *command, int *result){

    int pid; /*Identificador do processo*/
    int status; /*Estado do processo*/
    int i;
    char *args[MAX_ARGS]; /*MAX_ARGS esta definido na mylib.h e vale 1024*/
    int pipefd[2]; /*Comunicador entre os processos*/
    char c;
    char *delimitador = " \t";

    /* Este trecho divide a string command nas substrings correspondentes ao comando e argumentos */

    i = 0;
    args[i] = strtok(command, delimitador); /* Pega o comando, a primeira substring */
    while(  (args[++i] == strtok(NULL, delimitador))  ); /* Pega os argumentos, as substrings restantes */

    pipe(pipefd); /* Liga um processo ao outro */
    fcntl(pipefd[0], F_GETFL); /* Manipula as operações de controle no descritor de arquivo */

    /* Fork */
    pid = fork();

    /* Se o fork falhar, retorna 0 e nao seta resultado */
    if (pid < 0){
        return 0;
    }

    if(pid > 0){    /*Caller*/
        wait (&status); /*Espera o subprocesso parar*/

	/* Chamada com sucesso, mas falha na execução */
        if (read(pipefd[0], &c, 1) > 0){
            return -1;
        }

        if(WIFEXITED(status)){
            *result= WEXITSTATUS(status);
        }
        else{
            *result = -1;
        }

    }
    /* Processo filho */
    else{             
        close(pipefd[0]);
        execvp(args[0], args);
        write(pipefd[1], "deu ruim", 1);
        exit(-1);
    }

    /* Chamada realizada com sucesso e comando executado */
    return pid;
}










