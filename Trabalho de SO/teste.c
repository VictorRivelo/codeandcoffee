#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mylib.h"

int main (int argc, char**argv){

    int result, pid;
    char command[2048];

    strcpy(command, "ls -l -a");

    pid = run(command, &result);

    if(pid > 0){
        printf("Subprocesso retornou %d\n", result);
    }

    return 0;
}
