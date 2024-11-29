#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ListNode_destroy(ListNode* start){
    if(!start) return; 
    if(start->next) ListNode_destroy(start->next);
    if(start) free(start);
}

void ListNode_add(ListNode** start, int value){
    if((*start) == NULL){
        (*start) = newListNode(value);
        return;
    }

    ListNode* i = (*start);
    while(i->next != NULL) i = i->next;
    
    i->next = newListNode(value);
    return;
}

void ListNode_addAtStart(ListNode** start, int value){
    if((*start) == NULL){
        (*start) = newListNode(value);
        return;
    }

    ListNode* aux = newListNode(value);
    aux->next = (*start);
    (*start) = aux;
}

void ListNode_remove(ListNode** start, int value){
    if((*start)==NULL){
        error("Can't remove value from empty List");
        return;
    }

    if((*start)->value == value){
        ListNode* aux = (*start);
        (*start) = (*start)->next;
        free(aux);
        return;
    }

    ListNode *node, *ant = (*start);
    for(node = (*start)->next; node != NULL; node = node->next){
        if(node->value == value){
            ant->next = node->next;
            free(node);
            return;
        }
        ant = node;
    }

    error("Value not found in List");
}

ListNode* ListNode_get(ListNode *start, int value){
    ListNode *i = start;
    int j = 0;
    for(; i != NULL; i = i->next, j++){
        if(i->value == value){
            printf("Value %d is at postion %d in List <0x%x>\n", value, j, start);
            return i;
        }
    }

    printf("Value %d not found in List <0x%x>\n", value, start);
    return NULL;
}

void ListNode_print(ListNode* start){
    if(start==NULL){
        printf("List: empty.\n");
        return;
    }

    ListNode* i;
    int j;
    printf("List in <0x%x>:\n{\n", start);
    for(i=start, j=1; i!=NULL; i=i->next, j++){
        printf("  %2d", i->value);
        if(j==20){
            puts("");
            j = 0;
        }
    }
    puts("\n}");
}

ListNode* newListNode(int value){
    ListNode* self = (ListNode*) malloc(sizeof(ListNode));

    self->value = value;
    self->next = NULL;

    self->destroy = ListNode_destroy;
    self->add = ListNode_add;
    self->addAtStart = ListNode_addAtStart;
    self->remove = ListNode_remove;
    self->get = ListNode_get;
    self->print = ListNode_print;

    return self;
}