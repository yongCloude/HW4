#include "src/header/VirtualMemorySystem.h"


int nFrame;
int main(int argc, char const *argv[])
{
    ARGUMENT argument;
	FRAME_PAGE *phyMem = NULL;
	PAGE_TABLE *page_table = NULL;
	

    if(set_argument(argc, argv, &argument))
        printf("========Argument setting clear========\n");
    else
        return -1;

	nFrame = (1<<(argument.phyMemSizeBits-PAGESIZEBITS)); 
	assert(nFrame>0);

	if(initPhyMem(phyMem,nFrame))
		printf("========Physical memory initialized========\n");
	else
		return -1;

	printf("\nNum of Frames %d Physical Memory Size %ld bytes\n",nFrame, (1L<<argument.phyMemSizeBits));

	// init page table and opening trace file for each process
	page_table = (PAGE_TABLE*)malloc(sizeof(PAGE_TABLE) * argument.numProcess);
	for(int i=0; i<argument.numProcess; ++i){
		printf("process %d opening %s\n",i,argv[i+3]);
		init_oneLevel_page_table(page_table + i, i, argument.traceName[i]);
	}
	// ========================================================

    switch(argument.simulation_kinds){
        case ONE_LEVEL_FIFO:
			oneLevelVMSim(page_table, phyMem, ONE_LEVEL_FIFO, &argument);	// call oneLevelVMSim() with FIFO
            break;
        case ONE_LEVEL_LRU:
			oneLevelVMSim(page_table, phyMem, ONE_LEVEL_LRU);	// call oneLevelVMSim() with LRU
            break;	
        case TWO_LEVEL:
				// call twoLevelVMSim()
			break;
        case INVERTED:
				// call invertedPageVMsim()
            break;
        default:
            break;
    }

    return 0;
}

int set_argument(int argc, char *argv[], ARGUMENT *argument){

    if(argc < 4){
        printf("argument should be more than 4\n");
        return FALSE;
    }

    argument -> simulation_kinds = atoi(argv[1]);
    argument -> firstLevelBits = atoi(argv[2]);
    argument -> phyMemSizeBits = atoi(argv[3]);
    argument -> numProcess = argc - 4;
	argument -> traceName = (char*)malloc(sizeof(char) * argument->numProcess);
	for(int i=0; i<argument->numProcess; ++i){
		(argument -> traceName)[i]  = argv[i+3];
	}

    // s_flag later

    if (argument-> phyMemSizeBits < PAGESIZEBITS) {
		printf("PhysicalMemorySizeBits %d should be larger than PageSizeBits %d\n",argument -> phyMemSizeBits,PAGESIZEBITS);
        return FALSE; 
	}
	if (VIRTUALADDRBITS - PAGESIZEBITS - argument -> firstLevelBits <= 0 ) {
		printf("firstLevelBits %d is too Big for the 2nd level page system\n",argument -> firstLevelBits);
        return FALSE; 
	}

    return TRUE;
}


void oneLevelVMSim(PAGE_TABLE *pageTable, FRAME_PAGE *phyMemFrames, char FIFOorLRU, ARGUMENT const *argument) {
	
	// -s option print statement
	switch(FIFOorLRU){
		case ONE_LEVEL_FIFO:
			while(1){
				for(int i=0; i < argument->numProcess; ++i){
					int addr = read_addr(pageTable + i);
					if(check_frame_page(phyMemFrames, addr) == FALSE)
						push_frame_page(phyMemFrames, addr, i);
					

					
				}
			}
		case ONE_LEVEL_LRU:
	}
	
	printf("One-Level procID %d traceNumber %d virtual addr %x physical addr %x\n", i, procTable[i].ntraces,Vaddr,Paddr );
	
}


ADDRESS read_addr(PAGE_TABLE *page_table){

	ADDRESS addr;
	fscanf(page_table -> tracefp, "%x", &addr);
	while(getc(page_table -> tracefp) != '\n');
	return addr;
}

int check_frame_page(FRAME_PAGE *frame_page, ADDRESS addr){
	for(int i=0; i<nFrame; ++i){
		if((frame_page + i) -> virtualPageNumber == addr / GETVPN)
			return TRUE;
	}
	return FALSE;
}


void push_frame_page(FRAME_PAGE *frame_page, ADDRESS addr, int pid){

	for(int i=0; i<nFrame; ++i){
		if((frame_page + i) -> pid == -1 && (frame_page + i) -> virtualPageNumber == -1){
			(frame_page + i) -> pid = pid;
			(frame_page + i) -> virtualPageNumber = addr;
		}
	}

}