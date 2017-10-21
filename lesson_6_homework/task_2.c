#include <stdio.h>
#include "common/binary_tree.h"

int main() {
    t_function action = &printStringData;

    Node *root = makeNode("test");
    Node *left = appendNode(root, LEFT, makeNode("left_1"));
    Node *right = appendNode(root, RIGHT, makeNode("right_1"));

    traverseBinaryTreePreOrder(root, action);
    printf("\n");

    appendNode(left, LEFT, makeNode("left_1_left"));
    appendNode(left, RIGHT, makeNode("left_1_right"));
    appendNode(right, LEFT, makeNode("right_1_left"));
}
