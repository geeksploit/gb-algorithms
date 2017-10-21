#include <malloc.h>
#include "binary_tree.h"

Node *makeNode(void *data) {
    Node *node = (Node *) malloc(sizeof(Node));
    return node;
}