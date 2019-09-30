#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

typedef short test_cases;
typedef short num_chars;
typedef short number;
typedef short num_numbers;

number answer[2000];
num_numbers answerLength;
num_chars length, quantities[26], numbersLength[10];
char string[2001], *numbers[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
    test_cases numTestCases, caseNumber;
    num_chars i, j;
    num_numbers k;
    scanf("%hi", &numTestCases);
    REPEAT(i, 10) numbersLength[i] = (num_chars)strlen(numbers[i]);

    REPEAT(caseNumber, numTestCases) {
        scanf("%s", string);
        length = (num_chars)strlen(string);
        memset(quantities, 0, sizeof(quantities));
        REPEAT(i, length) quantities[string[i]-'A']++;
        answerLength = 0;

        /*
        0 -> Z
        2 -> W
        4 -> U
        6 -> X
        8 -> G
        ------
        1 -> O
        3 -> H
        5 -> F
        7 -> S
        ------
        9 -> I
        */
        REPEAT(i, quantities['Z'-'A']) {
            answer[answerLength++] = 0;
            REPEAT(j, numbersLength[0]) quantities[numbers[0][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['W'-'A']) {
            answer[answerLength++] = 2;
            REPEAT(j, numbersLength[2]) quantities[numbers[2][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['U'-'A']) {
            answer[answerLength++] = 4;
            REPEAT(j, numbersLength[4]) quantities[numbers[4][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['X'-'A']) {
            answer[answerLength++] = 6;
            REPEAT(j, numbersLength[6]) quantities[numbers[6][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['G'-'A']) {
            answer[answerLength++] = 8;
            REPEAT(j, numbersLength[8]) quantities[numbers[8][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['O'-'A']) {
            answer[answerLength++] = 1;
            REPEAT(j, numbersLength[1]) quantities[numbers[1][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['H'-'A']) {
            answer[answerLength++] = 3;
            REPEAT(j, numbersLength[3]) quantities[numbers[3][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['F'-'A']) {
            answer[answerLength++] = 5;
            REPEAT(j, numbersLength[5]) quantities[numbers[5][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['S'-'A']) {
            answer[answerLength++] = 7;
            REPEAT(j, numbersLength[7]) quantities[numbers[7][j]-'A']--;
            i--;
        }
        REPEAT(i, quantities['I'-'A']) {
            answer[answerLength++] = 9;
            REPEAT(j, numbersLength[9]) quantities[numbers[9][j]-'A']--;
            i--;
        }

        int compareNumbers(const void *ptr1, const void *ptr2) {
            number num1 = *(number*)ptr1, num2 = *(number*)ptr2;
            return (num1 > num2)-(num1 < num2);
        }
        qsort(answer, answerLength, sizeof(number), compareNumbers);
        printf("Case #%hi: ", caseNumber+1);
        REPEAT(k, answerLength) printf("%hi", answer[k]);
        puts("");
    }
    
    exit(0);
}