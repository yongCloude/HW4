#include <stdio.h>


int main(int argc, char const *argv[])
{
    
    int addr = 0x308b25e8;

    printf("%x\n", addr / (0x10 * 0x10 * 0x10));

   
    return 0;
}
