#include "../include/gerardosh.h"

int redirect(char **myargs, int length){
    //if a redirct command
    if(length >= 3 && strcmp(myargs[length - 2] , ">") == 0){
        //fork
        int rc = fork();
        if(rc < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc == 0){
            //save the current Standard out so you can redirect back instead of having the file as your permanent standard out
            int saved_stdout = dup(STDOUT_FILENO);
            if (saved_stdout == -1) {
                perror("Failed to save stdout");
                return 0;
            }
             //open the file, with the file path, writing, and truncate it
            int file = open(myargs[length-1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (file == -1) {
                perror("Failed to open file. File path might not exist.");
            }
            //redirect to the file as your Standard out
            else if (dup2(file, STDOUT_FILENO) == -1) {
                perror("Failed to redirect stdout");
            }

            // Redirect stderr to the file
            else if (dup2(file, STDERR_FILENO) == -1) {
                perror("Failed to redirect stderr");
            }
            //execute command
            else{
                //create your command array without the > file_path
                char *command[length - 2];
                for(int i = 0; i < length - 2; i++){
                    command[i] = myargs[i];
                }
                command[length -2] = NULL;
                //execute the command
                if(execvp(command[0], command) == -1){
                    perror("execvp failed");
                }
            }
            //redirect back to the old Standard Out
            if (dup2(saved_stdout, STDOUT_FILENO) == -1) {
                perror("Failed to restore stdout");
            }
            //close both Standard Outs
            close(saved_stdout);
            close(file);
            return 1;
        }
        else{
            //if parent wait
            wait(NULL);
            return 1;
        }
    }
    else
        //not a redirect command
        return 0;
}