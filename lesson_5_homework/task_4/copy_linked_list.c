#include <malloc.h>
#include "copy_linked_list.h"

ListNode *copyList(ListNode *node) {
}

ListNode *insertAfter(ListNode *node, ListValue value) {
    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->nextNode = node->nextNode;
    node->nextNode = new_node;

    new_node->value = value;
}
