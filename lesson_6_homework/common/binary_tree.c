#include <malloc.h>
#include <stdio.h>
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

void printStringData(TraverseAction action, void *data) {
    switch (action) {
        case ROOT_NODE:
            printf("%s", (char *) data);
            break;
        case PRE_LEFT:
            printf("(");
            break;
        case SEPARATOR:
            printf(",");
            break;
        case POST_RIGHT:
            printf(")");
            break;
        case NO_NODE:
            printf("NULL");
            break;
    }
}

// ​​“корень-левый-правый" - обход в прямом порядке
void traverseBinaryTreePreOrder(Node *node, t_function handler) {
    if (node == NULL)
        return;
    handler(ROOT_NODE, node->data);

    if (!node->left && !node->right)
        return;

    handler(PRE_LEFT, NULL);
    if (node->left)
        traverseBinaryTreePreOrder(node->left, handler);
    else
        handler(NO_NODE, NULL);

    handler(SEPARATOR, NULL);

    if (node->right)
        traverseBinaryTreePreOrder(node->right, handler);
    else
        handler(NO_NODE, NULL);
    handler(POST_RIGHT, NULL);
}

// ​​“левый​​-​​корень​​-​​правый”​(симметричный обход, in-order)
void traverseBinaryTreeInOrder(Node *node, t_function handler) {
    if (node == NULL)
        return;

    if (!node->left && !node->right) {
        handler(ROOT_NODE, node->data);
        return;
    }

    handler(PRE_LEFT, NULL);
}
