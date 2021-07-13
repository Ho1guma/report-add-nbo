#include <stdint.h>
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <arpa/inet.h>

int main(int argc, char** argv)
{
    FILE* fp1 = fopen(argv[1], "rb");
    FILE* fp2 = fopen(argv[2], "rb");

    uint8_t num1[4];
    uint8_t num2[4];

    fread(num1, sizeof(uint8_t),4,fp1);
    fread(num2, sizeof(uint8_t),4,fp2);
    uint32_t* p1 = reinterpret_cast<uint32_t*>(num1);
    uint32_t* p2 = reinterpret_cast<uint32_t*>(num2);
    uint32_t n1 = ntohl(*p1);
    uint32_t n2 = ntohl(*p2);
    //printf("32 bit number = 0x%08x\n",n1);
    //printf("32 bit number = 0x%08x\n",n2);
    printf("%d(0x%x)  + %d(0x%x) = %d(0x%x)", n2,n2,n1,n1,n1+n2,n1+n2);

}