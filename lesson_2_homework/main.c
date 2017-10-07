#include <stdio.h>
#include <stdlib.h>

int main() {
    void (*menu[])(void) = {&task0};

    return 0;
}

/*
 * Exit the application.
 */
void task0() {
    printf("thanks for staying with us, bye\n");
    exit(0);
}
