#ifndef LESSON_6_HOMEWORK_BINARY_TREE_H
#define LESSON_6_HOMEWORK_BINARY_TREE_H

enum TraverseAction {
    ROOT_NODE, PRE_LEFT, SEPARATOR, POST_RIGHT, NO_NODE
};
typedef enum TraverseAction TraverseAction;

typedef void(*t_function)(TraverseAction traverseAction, void *);

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

void traverseBinaryTreePreOrder(Node *node, t_function handler);
void printStringData(TraverseAction action, void *data);

#endif //LESSON_6_HOMEWORK_BINARY_TREE_H
