#include "../include/gerardosh.h"

char **tokenize(char *line) {
    int *line_info = tokenizing_init(line);
    int num_tokens = line_info[0];
    int biggest_token = line_info[1];
    free(line_info); // Free line_info after use

    char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *)); // +1 for NULL terminator
    char *token_buffer = (char *)malloc((biggest_token + 1) * sizeof(char)); // +1 for null terminator
    int tokenIndex = 0;
    int tokenNo = 0;
    int quotation = 0;

    for(int i = 0; i < (int)strlen(line); i++) {
        char readChar = line[i];
        if(readChar == '"' || readChar == '\'') {
            quotation ^= 1; // Toggle quotation state
            continue;
        }

        if (quotation) {
            token_buffer[tokenIndex++] = readChar;
        } else if (readChar == ' ' || readChar == '\n' || readChar == '\t') {
            if (tokenIndex > 0) {
                token_buffer[tokenIndex] = '\0';
                tokens[tokenNo] = (char *)malloc((tokenIndex + 1) * sizeof(char));
                strcpy(tokens[tokenNo++], token_buffer);
                tokenIndex = 0;
            }
        } else {
            token_buffer[tokenIndex++] = readChar;
        }
    }

    // Add the last token if any
    if (tokenIndex > 0) {
        token_buffer[tokenIndex] = '\0';
        tokens[tokenNo] = (char *)malloc((tokenIndex + 1) * sizeof(char));
        strcpy(tokens[tokenNo++], token_buffer);
    }

    tokens[tokenNo] = NULL; // NULL-terminate the tokens array
    free(token_buffer);
    return tokens;
}