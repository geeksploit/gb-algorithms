#include "common/binary_tree.h"

int main() {
    t_function action = &printStringData;

    Node *root = makeNode("test");
    Node *left = appendNode(root, LEFT, makeNode("left_1"));
    Node *right = appendNode(root, RIGHT, makeNode("right_1"));
}
