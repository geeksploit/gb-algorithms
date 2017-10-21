#ifndef LESSON_6_HOMEWORK_BINARY_TREE_H
#define LESSON_6_HOMEWORK_BINARY_TREE_H

struct Node {
    struct Node *parent;
    struct Node *left;
    struct Node *right;
    void *data;
};
typedef struct Node Node;

#endif //LESSON_6_HOMEWORK_BINARY_TREE_H
