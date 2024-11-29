#pragma once

#include <stdlib.h>
#include <stdio.h>

#define _self_copy_ struct ListNode*
#define _self_ struct ListNode**

typedef struct ListNode {
    int value;
    struct ListNode *next;

    void (*destroy) (_self_copy_);
    void (*add) (_self_, int value);
    void (*addAtStart) (_self_, int value);
    void (*remove) (_self_, int value);
    struct ListNode* (*get) (_self_copy_, int value);
    void (*print) (_self_copy_);
} ListNode;

ListNode* newListNode(int value);
