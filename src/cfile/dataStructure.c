#include "../header/dataStructure.h"

void init_queue(TABLE_QUEUE *que){
    que -> front = NULL;
    que -> rear = NULL;
}

int check_queue_empty(TABLE_QUEUE *que){
    if(que -> front == NULL)
        return TRUE;
    else 
        return FALSE;
}

void Enqueue(TABLE_QUEUE *que, PT_ENTRY *pt_entry){

    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
        printf("malloc failed!\n");
    node -> next = NULL;
    node -> pt_entry = pt_entry;

    if(que -> front == NULL){
        que -> front = node;
        que -> rear = node;
    }
    else{
        que -> rear -> next = node;
        que -> rear = node;
    }

}

PT_ENTRY* Dequeue(TABLE_QUEUE *que){

    if(check_queue_empty(que) == TRUE){
        printf("que is empty!\n");
        return NULL;
    }

    Node *del = que -> front;
    PT_ENTRY *ret = que -> front -> pt_entry;
    que -> front = que -> front -> next;
    free(del);

    return ret;
}