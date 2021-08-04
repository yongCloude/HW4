#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "memory.h"

typedef struct argument{
    int firstLevelBits; 
    int phyMemSizeBits; 
    int numProcess;
    int s_flag;
    int simulation_kinds;
    char *traceName;
}ARGUMENT;


int set_argument(int argc, char *argv[], ARGUMENT *argument);
void oneLevelVMSim(PAGE_TABLE *pageTable, FRAME_PAGE *phyMemFrames, char FIFOorLRU, ARGUMENT const *argument);
ADDRESS read_addr(PAGE_TABLE *page_table);
int check_frame_page(FRAME_PAGE *frame_page, ADDRESS addr);
void push_frame_page(FRAME_PAGE *frame_page, ADDRESS addr, int pid);
ADDRESS search_page_table()
