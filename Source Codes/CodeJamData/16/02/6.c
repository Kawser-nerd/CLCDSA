#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

typedef long test_cases;
typedef long num_moves;
typedef size_t length;
typedef char string[101];

string storage;
length sequenceLength, maxPlus, maxMin;
bool sequence[100];
num_moves numMoves;

int main() {
    length i;
    test_cases numTestCases, caseNumber;
    bool stillOnPlus, stillOnMin;
    scanf("%li", &numTestCases);

    REPEAT(caseNumber, numTestCases) {
        scanf("%s", storage);
        sequenceLength = strlen(storage);
        stillOnPlus = stillOnMin = true, maxPlus = maxMin = numMoves = 0;
        REPEAT(i, sequenceLength) {
            sequence[i] = (storage[i] == '+');
            if (stillOnPlus) {
                if (sequence[i]) maxPlus = i+1;
                else stillOnPlus = false;
            }
            if (!stillOnPlus && stillOnMin) {
                if (!sequence[i]) maxMin = i+1;
                else stillOnMin = false;
            }
        }
        while (maxPlus < sequenceLength) {
            numMoves++;
            if (maxPlus) numMoves++;
            maxPlus = maxMin, stillOnPlus = true;
            for (i = maxPlus; i < sequenceLength; i++) {
                if (stillOnPlus) {
                    if (sequence[i]) maxPlus = i+1;
                    else stillOnPlus = false;
                }
                if (!stillOnPlus) {
                    if (!sequence[i]) maxMin = i+1;
                    else break;
                }
            }
        }
        printf("Case #%li: %li\n", caseNumber+1, numMoves);
    }

    exit(0);
}