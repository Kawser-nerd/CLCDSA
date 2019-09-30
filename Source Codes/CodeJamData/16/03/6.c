#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef signed char byte;
#define REPEAT(token, num) for (token = 0; token < num; token++)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
static inline void POPQUEUE(void *arr, size_t length, size_t itemSize) { memmove(arr, arr+itemSize, length*itemSize); }
static inline void REMOVEELEM(void *arr, size_t offset, size_t length, size_t itemSize) { memmove(arr+(offset*itemSize), arr+((offset+1)*itemSize), (length-offset)*itemSize); }
static inline void REMOVEELEMS(void *arr, size_t offset, size_t numElems, size_t length, size_t itemSize) { memmove(arr+(offset*itemSize), arr+((offset+numElems)*itemSize), (length-offset)*itemSize); }
//#define DEBUG
#ifdef DEBUG
#define PRINTF printf
#else
#define PRINTF(...) 1
#endif

typedef short num_bits;
typedef short num_nums;

num_nums numNeeded;
num_bits length;
char string[10000];

int main() {
    num_nums i;
    num_bits j;
    byte storage;
    scanf("%hhi", &storage);
    puts("Case #1:");
    scanf("%hi %hi", &length, &numNeeded);

    REPEAT(i, numNeeded) {
        if (!i) REPEAT(j, length) string[j] = (((j == 0) || (j+1 == length)) ? '1' : '0');
        else REPEAT(j, length) string[j] = (((j == 0) || (j+1 == length) || (i & (1 << ((j-1)/2)))) ? '1' : '0');
        printf("%s 3 4 5 6 7 8 9 10 11\n", string);
    }

    exit(0);
}