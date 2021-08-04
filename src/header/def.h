
#define PAGESIZEBITS 12			// page size = 4Kbytes
#define VIRTUALADDRBITS 32		// virtual address space size = 4Gbytes
#define TRUE 1
#define FALSE 0
#define GETVPN 0x10 * 0x10 * 0x10


typedef int ADDRESS;

typedef enum simulation_type{
    ONE_LEVEL_FIFO,
    ONE_LEVEL_LRU,
    TWO_LEVEL,
    INVERTED
}SIMULATION_TYPE;

