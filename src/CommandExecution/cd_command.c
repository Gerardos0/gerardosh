#include "../include/gerardosh.h"

int cd_command(char **myargs, int length){
    if (strcmp(myargs[0], "cd") == 0 ) {
        if (length != 2) {
            fprintf(stderr, "Shell: Incorrect command\n");
        }
        else {
            if (chdir(myargs[1]) != 0) {
                fprintf(stderr, "Shell: Directory '%s' does not exist\n", myargs[1]);
            }
        return 1;
        }
    }
    else if(strcmp(myargs[0], "cd..") == 0){
        if (chdir("..") != 0) {
            fprintf(stderr, "Shell: Failed to change to parent directory");
        }
        return 1;
    }
    else
        return 0;
    return 0;
}