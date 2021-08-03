#include "../header/memory.h"

void init_oneLevel_page_table(PAGE_TABLE* pageTable, int pid, char *traceName){

    TABLE_QUEUE *table_queue = (TABLE_QUEUE*)malloc(sizeof(TABLE_QUEUE));
    init_queue(table_queue);
    
    pageTable -> pid = pid;
    pageTable -> num2ndLevelPageTable = 0;
    pageTable -> numIHTConflictAccess = 0;
    pageTable -> ntraces = 0;
    pageTable -> numIHTNULLAccess = 0;
    pageTable -> numIHTNonNULLAcess = 0;
    pageTable -> numPageFault = 0;
    pageTable ->  numPageHit = 0;
    pageTable -> firstLevelPageTable = table_queue;
    strcpy(pageTable -> traceName, traceName);
}