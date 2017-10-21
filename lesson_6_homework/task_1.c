#include <mem.h>

unsigned int hash_sum(char *input_string);

int main() {
    return 0;
}

unsigned int hash_sum(char *input_string) {
    unsigned int hash = 0;
    for (int i = 0, size = strlen(input_string); i < size; i++) {
        hash += input_string[i];
    }
    return hash;
}