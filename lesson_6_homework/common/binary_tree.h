#ifndef LESSON_6_HOMEWORK_BINARY_TREE_H
#define LESSON_6_HOMEWORK_BINARY_TREE_H

enum SplitDirection {
    LEFT, RIGHT
};
typedef enum SplitDirection SplitDirection;

struct Node {
    struct Node *parent;
    struct Node *left;
    struct Node *right;
    void *data;
};
typedef struct Node Node;

Node *makeNode(void *data);
Node *appendNode(Node *parent, SplitDirection splitDirection, Node *child);

#endif //LESSON_6_HOMEWORK_BINARY_TREE_H
