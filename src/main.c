#include "../include/gerardosh.h"

int main(void) {
     char* line = NULL;
     size_t len = 0;
     char **tokens;
     int i;

     while(1) {
         printf("\nGerardoSh$ ");
         ssize_t read = getline(&line, &len, stdin);

         // Handle getline errors or EOF
         if (read == -1) {
             continue;
         }

         // Strip newline
         if (read > 0 && line[read - 1] == '\n') {
             line[read - 1] = '\0';
         }

         tokens = tokenize(line);

         // Free line immediately after tokenization and reset pointers
         free(line);
         line = NULL;  // Reset line to NULL
         len = 0;      // Reset len to 0

         // Process tokens
         int index = 0;
         int length = 0;
         while(tokens[index] != NULL) {
             length++;
             index++;
         }

         if(length != 0) {
             char *myargs[length + 1]; // +1 for NULL terminator
             for(i = 0; tokens[i] != NULL; i++) {
                 myargs[i] = strdup(tokens[i]);
             }
             myargs[length] = NULL;

             if(pipeline(myargs, length)) {
                 // Cleanup myargs if not used
                 for(int j = 0; j < length; j++) free(myargs[j]);
                 continue;
             }

             if(redirect(myargs, length)) {
                 for(int j = 0; j < length; j++) free(myargs[j]);
                 continue;
             }

             if(cd_command(myargs, length)) {
                 for(int j = 0; j < length; j++) free(myargs[j]);
                 continue;
             }

             exit_command(myargs[0]);
             command(myargs);

             // Free myargs after command execution
             for(int j = 0; j < length; j++) free(myargs[j]);
         }

         // Free tokens
         for(i = 0; tokens[i] != NULL; i++) {
             free(tokens[i]);
         }
         free(tokens);
     }
     return 0;
 }