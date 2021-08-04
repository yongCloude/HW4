#include "../header/memory.h"

void init_oneLevel_page_table(PAGE_TABLE* pageTable, int pid, const char *traceName){

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
    pageTable -> tracefp = fopen(pageTable -> traceName, "r");
    rewind(pageTable -> tracefp);
}

int initPhyMem(FRAME_PAGE *phyMem, int nFrame) {
	int i;

    phyMem = (FRAME_PAGE*)malloc(sizeof(FRAME_PAGE) * nFrame);
    if(phyMem == NULL)
        return FALSE;

	for(i = 0; i < nFrame; i++) {
		phyMem[i].number = i;
		phyMem[i].pid = -1;
		phyMem[i].virtualPageNumber = -1;
		phyMem[i].lruLeft = &phyMem[(i-1+nFrame) % nFrame];
		phyMem[i].lruRight = &phyMem[(i+1+nFrame) % nFrame];
	}

	//oldestFrame = &phyMem[0];

    return TRUE;

}