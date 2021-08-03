
VMS : dataStructure.o memory.o VirtualMemorySystem.o
	gcc -o VMS VirtualMemorySystem.o dataStructure.o memory.o

VirtualMemorySystem.o:
	gcc -c -o VirtualMemorySystem.o VirtualMemorySystem.c

dataStructure.o :
	gcc -c -o dataStructure.o src/cfile/dataStructure.c

memory.o :
	gcc -c -o memory.o src/cfile/memory.c