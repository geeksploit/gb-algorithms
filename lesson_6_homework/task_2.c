/*
 * 2. Переписать программу, реализующее двоичное дерево поиска.
 * а) Добавить в него обход дерева различными способами;
 */

#include <stdio.h>
#include "common/binary_tree.h"

int main() {
    t_function action = &printStringData;

    Node *root = makeNode("root");
    Node *left = appendNode(root, LEFT, makeNode("root-left"));
    Node *right = appendNode(root, RIGHT, makeNode("root-right"));

    traverseBinaryTreePreOrder(root, action);
    printf("\n");

    appendNode(left, LEFT, makeNode("left-left"));
    appendNode(left, RIGHT, makeNode("left-right"));
    appendNode(right, LEFT, makeNode("right-left"));

    traverseBinaryTreePreOrder(root, action);
    printf("\n");

    traverseBinaryTreeInOrder(root, action);
    printf("\n");

    traverseBinaryTreePostOrder(root, action);
    printf("\n");
}
