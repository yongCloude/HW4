#include <stdlib.h>
#include "def.h"

typedef struct pageTableEntry PT_ENTRY;

typedef struct myQueue{
    struct _node *front;
    struct _node *rear;
}TABLE_QUEUE;

typedef struct _node{
    PT_ENTRY *pt_entry;
    struct _node *next;
}Node;


void init_queue(TABLE_QUEUE *que);
int check_queue_empty(TABLE_QUEUE *que);
void Enqueue(TABLE_QUEUE *que, PT_ENTRY *pt_entry);
PT_ENTRY* Dequeue(TABLE_QUEUE *que);