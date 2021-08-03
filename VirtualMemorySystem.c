#include "src/header/VirtualMemorySystem.h"



int main(int argc, char const *argv[])
{
    ARGUMENT argument;
	
	//PAGE_TABLE *pageTable = (PAGE_TABLE*)malloc(sizeof(PAGE_TABLE) * numProcess);

    if(set_argument(argc, argv, &argument))
        printf("========Argument setting clear========\n");
    else
        return -1;

    


    switch(argument.simulation_kinds){
        case ONE_LEVEL_FIFO:

            break;
        case ONE_LEVEL_LRU:
            break;
        case TWO_LEVEL:
            break;
        case INVERTED:
            break;
        default:
            break;
    }













    // initialize procTable for memory simulations
	// for(i = 0; i < numProcess; i++) {
	// 	// opening a tracefile for the process
	// 	printf("process %d opening %s\n",i,argv[i+3]);
	// 	(pageTable + i) -> tracefp = file_open(argv[i+3]);
		
	// 	if((pageTable + i) -> tracefp == NULL)
	// 		printf("process %d file open failed\n", i);
	// }

    // int nFrame = (1<<(phyMemSizeBits-PAGESIZEBITS)); assert(nFrame>0);
	// phyMem = (FRAME_PAGE*)malloc(sizeof(FRAME_PAGE));
	// oldestFrame = initPhyMem(phyMem, nFrame);

    // printf("\nNum of Frames %d Physical Memory Size %ld bytes\n",nFrame, (1L<<phyMemSizeBits));
	
	// // initialize procTable for the simulation
	// for(i = 0; i < numProcess; i++) {
	// 	// initialize procTable fields
	// 	// rewind tracefiles
	// 	init_page_table(pageTable + i, i, argv[i+3]);
	// 	rewind(pageTable[i].tracefp);
	// }
	

	// switch(atoi(argv[1])){
	// 	case ONE_LEVEL_FIFO:
	// 		oneLevelVMSim(pageTable, phyMem, ONE_LEVEL_FIFO);
	// 	case ONE_LEVEL_LRU:
	// 		oneLevelVMSim(pageTable, phyMem, ONE_LEVEL_LRU);
	// 	case TWO_LEVEL:
	// 	case INVERTED:
	// 	default:
	// 		break;
	// }


	// call oneLevelVMSim() with FIFO
	
	
	
	// call oneLevelVMSim() with LRU
		
	// initialize procTable for the simulation
	
	// call twoLevelVMSim()

	// initialize procTable for the simulation
	
	// call invertedPageVMsim()
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


// void oneLevelVMSim(PAGE_TABLE *pageTable, FRAME_PAGE *phyMemFrames, char FIFOorLRU) {
	
// 	// -s option print statement
// 	//printf("One-Level procID %d traceNumber %d virtual addr %x physical addr %x\n", i, procTable[i].ntraces,Vaddr,Paddr );
// 	switch(FIFOorLRU){
// 		case ONE_LEVEL_FIFO:
			
// 		case ONE_LEVEL_LRU:
// 	}
// 	print_simulation_result(pageTable, numProcess);	
	
// }


// ADDRESS read_addr(PAGE_TABLE *page_table){

// 	ADDRESS addr;
// 	fscanf(page_table -> tracefp, "%d", &addr);
// 	while(getchar() != '\n');
// 	return addr;
// }