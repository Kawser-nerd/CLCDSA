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

typedef long test_cases;
typedef long length;
typedef long complexity;
typedef long long place;

complexity sequenceComplexity;
length numStudents, sequenceLength, numbers[200], numAnswers;
place answers[100];

int main() {
    test_cases numTestCases, caseNumber;
    length i;
    scanf("%li", &numTestCases);

    REPEAT(caseNumber, numTestCases) {
        scanf("%li %li %li", &sequenceLength, &sequenceComplexity, &numStudents);
        numAnswers = 0, memset(answers, 0, sizeof(answers));
        REPEAT(i, 200) numbers[i] = i % sequenceLength;

        for (numAnswers = 0; numAnswers*sequenceComplexity < sequenceLength; numAnswers++) REPEAT(i, sequenceComplexity) answers[numAnswers] *= sequenceLength, answers[numAnswers] += numbers[numAnswers*sequenceComplexity+i];
        
        if (numAnswers > numStudents) printf("Case #%li: IMPOSSIBLE\n", caseNumber+1);
        else {
            printf("Case #%li: ", caseNumber+1);
            REPEAT(i, numAnswers) printf("%lli%c", answers[i]+1, ((i+1 == numAnswers) ? '\n' : ' '));
        }
    }

    exit(0);
}