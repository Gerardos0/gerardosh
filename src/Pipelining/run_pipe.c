#include "../include/gerardosh.h"

void run_pipe(char ***commands, int number_commands){
    // Create pipes and store PID of each fork
    int pfd[2 * (number_commands-1)];
	int pid[number_commands];

	//Set up each pipe for read and write
	for(int i = 0; i< number_commands - 1; i++){
	    if(pipe(pfd + i*2) == -1){
	        char error_message[30] = "An error has occurred\n";
            write(STDERR_FILENO, error_message, strlen(error_message));
	        exit(1);
	    }
	}

	// set up the pipes for each fork so that they are all connected
    for(int i = 0; i < number_commands; i++){
        pid[i] = fork();
        if ( pid[i] == 0) {
            if (i > 0) {
                // If the process is not the first command, redirect stdin from the previous pipe
                dup2(pfd[(i - 1) * 2], STDIN_FILENO);
            }

            if (i < number_commands - 1) {
                // If the process is not the last command, redirect stdout to the next pipe
                dup2(pfd[i * 2 + 1], STDOUT_FILENO);
            }

            // Close all pipe file descriptors in the child process copy, because they are no longer needed
            for (int j = 0; j < 2 * (number_commands - 1); j++) {
                close(pfd[j]);
            }

            // Execute the command for that child
            execvp(commands[i][0], commands[i]);
            char error_message[30] = "An error has occurred\n";
            write(STDERR_FILENO, error_message, strlen(error_message));
            exit(1);
        }
        else if (pid[i] == -1){
            char error_message[30] = "An error has occurred\n";
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
    }
    // if parent close all the pipes because they arent needed
    for(int i = 0; i < 2 * (number_commands -1);i++)
        close(pfd[i]);

    //parent waits on each child
    for(int i = 0; i < number_commands; i++)
        waitpid(pid[i], NULL, 0);
}