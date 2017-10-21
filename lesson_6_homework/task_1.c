#include <mem.h>

#define MAX_LINE_LENGTH 255

unsigned int hash_sum(char *input_string);

int main() {
    char input_string[MAX_LINE_LENGTH];
    return 0;
}

unsigned int hash_sum(char *input_string) {
    unsigned int hash = 0;
    for (int i = 0, size = strlen(input_string); i < size; i++) {
        hash += input_string[i];
    }
    return hash;
}