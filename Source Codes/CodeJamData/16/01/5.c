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
typedef long number;

number query, answer;
bool foundDigits[10];

int main() {
    number multiplier, digit, curNumber;
    test_cases numTestCases, caseNumber;
    bool allDigitsFound;
    scanf("%li", &numTestCases);

    REPEAT(caseNumber, numTestCases) {
        scanf("%li", &query);
        memset(foundDigits, false, sizeof(foundDigits));
        answer = -1, multiplier = 1;
        if (query) while (true) {
            curNumber = multiplier*query;
            while (curNumber) foundDigits[curNumber % 10] = true, curNumber /= 10;
            allDigitsFound = true;
            REPEAT(digit, 10) allDigitsFound &= foundDigits[digit];
            if (allDigitsFound) {
                answer = multiplier*query;
                break;
            }
            multiplier++;
        }
        if (answer == -1) printf("Case #%li: INSOMNIA\n", caseNumber+1);
        else printf("Case #%li: %li\n", caseNumber+1, answer);
    }
    
    exit(0);
}