#include "../include/gerardosh.h"

int *tokenizing_init(char *line) {
    int current = 0;
    int num_tokens = 0;
    int biggest_token = 0;
    int current_token_size = 0;
    bool in_a_word = false;
    bool in_quotes = false;

    if (!line) {
        int *results = malloc(2 * sizeof(int));
        results[0] = 0;
        results[1] = 0;
        return results;
    }

    while (line[current] != '\0') {
        if (line[current] == '"' || line[current] == '\'') {
            in_quotes = !in_quotes;
            current++;
            continue;
        }

        if (in_quotes) {
            current_token_size++;
            current++;
            continue;
        }

        if (line[current] != ' ') {
            if (!in_a_word) {
                num_tokens++;
                in_a_word = true;
                current_token_size = 1;
            } else {
                current_token_size++;
            }
        } else {
            if (in_a_word) {
                if (current_token_size > biggest_token) {
                    biggest_token = current_token_size;
                }
                current_token_size = 0;
                in_a_word = false;
            }
        }
        current++;
    }
    int *results = malloc(2 * sizeof(int));
    results[0] = 0;
    results[1] = 0;
    return results;
}