#ifndef LESSON_5_HOMEWORK_STACK_WITH_MEMORY_CHECK_H
#define LESSON_5_HOMEWORK_STACK_WITH_MEMORY_CHECK_H

#define T long

struct TNode {
    T value;
    struct TNode *next;
};
typedef struct TNode Node;

struct TStack {
    Node *head;
};
typedef struct TStack Stack;

void pushStack(Stack *stack, T value);

#endif //LESSON_5_HOMEWORK_STACK_WITH_MEMORY_CHECK_H
