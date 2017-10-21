#include <malloc.h>
#include "binary_tree.h"

Node *makeNode(void *data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

Node *appendNode(Node *parent, SplitDirection splitDirection, Node *child) {

    switch (splitDirection) {
        case LEFT:
            parent->left = child;
            break;
        case RIGHT:
            parent->right = child;
            break;
    }

    child->parent = parent;

    return child;
}