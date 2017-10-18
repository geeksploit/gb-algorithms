#include <malloc.h>
#include "copy_linked_list.h"

ListNode *copyList(ListNode *source_list) {
    ListNode *new_list = (ListNode *) malloc(sizeof(ListNode));
    if (new_list == NULL || source_list == NULL) {
        return NULL;
    }

    ListNode *cursor = source_list;
    ListNode *new_cursor = new_list;

    new_list->nextNode = NULL;
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
