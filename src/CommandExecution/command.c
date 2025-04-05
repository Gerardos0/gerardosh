#include "../include/gerardosh.h"

void command(char **myargs){
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        execvp(myargs[0], myargs);
        perror("execvp failed");
        exit(1);
    } else{
        wait(NULL);
    }
}
