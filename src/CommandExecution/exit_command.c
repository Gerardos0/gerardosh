#include "../include/gerardosh.h"

void exit_command(char *command){
    if(strcmp(command, "exit") == 0)
        exit(0);
}
