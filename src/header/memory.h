#include <stdio.h>
#include <string.h>
#include "dataStructure.h"

typedef struct procEntry {
	char *traceName;			// the memory trace name
	int pid;					// process (trace) id
	int num2ndLevelPageTable;	// The 2nd level page created(allocated);
	int numIHTConflictAccess; 	// The number of Inverted Hash Table Conflict Accesses
	int ntraces;				// the number of memory traces
	int numIHTNULLAccess;		// The number of Empty Inverted Hash Table Accesses
	int numIHTNonNULLAcess;		// The number of Non Empty Inverted Hash Table Accesses
	int numPageFault;			// The number of page faults
	int numPageHit;				// The number of page hits
	void* firstLevelPageTable;
	FILE *tracefp;
}PAGE_TABLE;

typedef struct pageTableEntry {
	int level;				// page table level (1 or 2)
	char valid;
	struct pageTableEntry *secondLevelPageTable;	// valid if this entry is for the first level page table (level = 1)
	int frameNumber;								// valid if this entry is for the second level page table (level = 2)
}PT_ENTRY;

typedef struct framePage {
	int number;			// frame number
	int pid;			// Process id that owns the frame
	int virtualPageNumber;			// virtual page number using the frame
	struct framePage *lruLeft;	// for LRU circular doubly linked list
	struct framePage *lruRight; // for LRU circular doubly linked list
}FRAME_PAGE;

struct invertedPageTableEntry {
	int pid;					// process id
	int virtualPageNumber;		// virtual page number
	int frameNumber;			// frame number allocated
	struct invertedPageTableEntry *next;
};


FRAME_PAGE* initPhyMem(FRAME_PAGE *phyMem, int nFrame);
void init_oneLevel_page_table(PAGE_TABLE *pageTable, int pid, char *traceName);
