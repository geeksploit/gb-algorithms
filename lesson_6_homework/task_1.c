#include <stdio.h>
#include <mem.h>

#define MAX_LINE_LENGTH 255
#define EVALUATE(x) #x
#define STRINGIFY(x) EVALUATE(x)

unsigned int hash_sum(char *input_string);

int main() {
    char input_string[MAX_LINE_LENGTH];
    printf("please enter a string of characters: ");
    scanf("%" STRINGIFY(MAX_LINE_LENGTH) "s", input_string);

    return 0;
}

unsigned int hash_sum(char *input_string) {
    unsigned int hash = 0;
    for (int i = 0, size = strlen(input_string); i < size; i++) {
        hash += input_string[i];
    }
    return hash;
}