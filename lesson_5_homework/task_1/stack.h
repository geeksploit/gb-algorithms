#ifndef LESSON_5_HOMEWORK_INTEGER_STACK_H
#define LESSON_5_HOMEWORK_INTEGER_STACK_H

#define T int

struct TNode {
    T value;
    struct TNode *next;
};
typedef struct TNode Node;

struct Stack {
    Node *head;
    int size;
    int maxSize;
};

#endif //LESSON_5_HOMEWORK_INTEGER_STACK_H
