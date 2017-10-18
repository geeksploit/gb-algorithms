#include <malloc.h>
#include "copy_linked_list.h"

ListNode *copyList(ListNode *source_list) {
    ListNode *new_list = (ListNode *) malloc(sizeof(ListNode));
    if (new_list == NULL || source_list == NULL) {
        return NULL;
    }

    ListNode *source_cursor = source_list;
    ListNode *new_cursor = new_list;

    new_list->value = source_list->value;
    new_list->nextNode = NULL;

    while (source_cursor->nextNode != NULL) {
        source_cursor = source_cursor->nextNode;
        new_cursor = insertAfter(new_cursor, source_cursor->value);
    }

    return new_list;
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
