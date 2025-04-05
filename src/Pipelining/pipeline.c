#include "../include/gerardosh.h"

int pipeline(char ** myargs, int length){
    //if the command is less than 3 then it isnt a pipe
    if(length >= 3){
        int contains_pipe = 0;
        //loop through each token and check if it is a pipe
        for(int i = 0; i < length; i++){
            if(strcmp(myargs[i], "|") == 0){
                //if it is then make a flag that it is
                contains_pipe = 1;
                break;
            }
        }
        if(contains_pipe){
            //make a new array that stores each command with each word seperated into an index
            // so all_commands[command][word(string so char*)]
            //    char*        *        *
            char **commands[(length/2 + 1)];
            int number_commands = 0;
            int index = 0;
            //while you havent gone through every token ( create the commands array)
            while(index < length){
                int number_args = 0;
                //count the words for the current command checking if you hit a "|"
                for(int j = index; j< length; j++){
                    if(strcmp(myargs[j], "|") == 0)
                        break;
                    else
                        number_args += 1;
                }
                //Create the array that holds each word in the command
                char **cmd = (char **)malloc((number_args + 1) * sizeof(char *));
                for(int i = 0; i < number_args; i++){
                    cmd[i] = myargs[index + i];
                }
                //array end
                cmd[number_args] = NULL;
                //save the command in the commands array
                commands[number_commands] = cmd;
                number_commands ++;
                index += number_args;
                //if you are at a pipe then incrament the index (words seen) so you can skip the "|"
                if (index < length && strcmp(myargs[index], "|") == 0)
                    index++;
            }
            //end commands
            commands[number_commands] = NULL;
            int pid;
            //fork since you are in the shell currently
            pid = fork();
            if(pid == 0)
                //if child start running the commands
                run_pipe(commands, number_commands);
            else if(pid == -1){
                char error_message[30] = "An error has occurred\n";
                write(STDERR_FILENO, error_message, strlen(error_message));
                return 0;
            }
            else{
                //if parent wait
                wait(NULL);
            }
            //free all you allocated memory you made when building the commands array
            for(int i = 0; i < number_commands; i++){
                free(commands[i]);
            }
            //return success
            return 1;
        }
        //return fail
        return 0;
    }
    //return not a pipe command
    return 0;
}
