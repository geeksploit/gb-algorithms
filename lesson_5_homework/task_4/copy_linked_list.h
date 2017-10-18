#ifndef LESSON_5_HOMEWORK_COPY_LINKED_LIST_H
#define LESSON_5_HOMEWORK_COPY_LINKED_LIST_H

#define ListValue char

struct ListNodeStruct {
    ListValue value;
    struct ListNodeStruct nextNode;
};
typedef struct ListNodeStruct ListNode;

#endif //LESSON_5_HOMEWORK_COPY_LINKED_LIST_H
