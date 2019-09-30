#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
typedef long long number;

num_chars length, numBothUnknown, numBothUnknownStore;
char coders[20], jammers[20], newCoders[20], newJammers[20], newCoders2[20], newJammers2[20];
bool codersIsBetter, jammersIsBetter, oldCodersIsBetter, oldJammersIsBetter;
number codersValue, jammersValue, oldCodersValue, oldJammersValue, answer1, answer2;

long long getCloser(char *coders, char *jammers) {
    num_chars i;
    numBothUnknown = 0;
    codersIsBetter = jammersIsBetter = false;
    codersValue = jammersValue = 0;
    REPEAT(i, length) {
        if (!codersIsBetter && !jammersIsBetter) {
            if (coders[i] != '?') {
                if (jammers[i] != '?') {
                    if (coders[i] > jammers[i]) codersIsBetter = true;
                    else if (coders[i] < jammers[i]) jammersIsBetter = true;
                }
                else jammers[i] = coders[i];
            } else if (jammers[i] != '?') coders[i] = jammers[i];
            else coders[i] = jammers[i] = '0';
            if (!codersIsBetter && !jammersIsBetter) numBothUnknown++;
        } else if (codersIsBetter) {
            if (coders[i] == '?') coders[i] = '0';
            if (jammers[i] == '?') jammers[i] = '9';
        } else if (jammersIsBetter) {
            if (jammers[i] == '?') jammers[i] = '0';
            if (coders[i] == '?') coders[i] = '9';
        }
        
        codersValue *= 10, codersValue += coders[i];
        jammersValue *= 10, jammersValue += jammers[i];
    }
    return (codersIsBetter ? (codersValue-jammersValue) : (jammersValue-codersValue));
}

int main() {
    test_cases numTestCases, caseNumber;
    num_chars i;
    scanf("%hi", &numTestCases);

    REPEAT(caseNumber, numTestCases) {
        scanf("%s %s", coders, jammers);
        //printf("%s %s\n", coders, jammers);
        length = (num_chars)strlen(coders);
        memcpy(newCoders, coders, sizeof(newCoders)), memcpy(newJammers, jammers, sizeof(newJammers));
        answer1 = getCloser(newCoders, newJammers);
        if (answer1 < 0) puts("sfgg");
        if (!numBothUnknown || !answer1) printf("Case #%hi: %s %s\n", caseNumber+1, newCoders, newJammers);
        else {
            numBothUnknownStore = numBothUnknown, oldCodersValue = codersValue, oldJammersValue = jammersValue, oldCodersIsBetter = codersIsBetter, oldJammersIsBetter = jammersIsBetter;
            REPEAT(i, numBothUnknownStore) {
                memcpy(newCoders2, coders, sizeof(newCoders)), memcpy(newJammers2, jammers, sizeof(newJammers));
                if (newCoders2[numBothUnknownStore-i-1] == '?' && newJammers2[numBothUnknownStore-i-1] == '?') {
                    if (oldCodersIsBetter) newJammers2[numBothUnknownStore-i-1] = '1', newCoders2[numBothUnknownStore-i-1] = '0';
                    else if (oldJammersIsBetter) newCoders2[numBothUnknownStore-i-1] = '1', newJammers2[numBothUnknownStore-i-1] = '0';
                } else if (newCoders2[numBothUnknownStore-i-1] == '?') {
                    if (oldCodersIsBetter && newJammers2[numBothUnknownStore-i-1] != '0') newCoders2[numBothUnknownStore-i-1] = newJammers2[numBothUnknownStore-i-1]-1;
                    else if (oldJammersIsBetter && newJammers2[numBothUnknownStore-i-1] != '9') newCoders2[numBothUnknownStore-i-1] = newJammers2[numBothUnknownStore-i-1]+1;
                    else continue;
                } else if (newJammers2[numBothUnknownStore-i-1] == '?') {
                    if (oldJammersIsBetter && newCoders2[numBothUnknownStore-i-1] != '0') newJammers2[numBothUnknownStore-i-1] = newCoders2[numBothUnknownStore-i-1]-1;
                    else if (oldCodersIsBetter && newCoders2[numBothUnknownStore-i-1] != '9') newJammers2[numBothUnknownStore-i-1] = newCoders2[numBothUnknownStore-i-1]+1;
                    else continue;
                } else continue;
                //if (caseNumber == 15) printf("%s %s\n", newCoders2, newJammers2);
                answer2 = getCloser(newCoders2, newJammers2);
                //if (caseNumber == 15) printf("%hi %lli %lli %s %s %s %s\n", i, answer1, answer2, newCoders, newJammers, newCoders2, newJammers2);
                if (answer2 <= 0) puts("sfg");
                if ((answer1 > answer2) || ((answer1 == answer2) && ((codersValue < oldCodersValue) || ((codersValue == oldCodersValue) && (jammersValue < oldJammersValue))))) memcpy(newCoders, newCoders2, sizeof(newCoders)), memcpy(newJammers, newJammers2, sizeof(newJammers)), answer1 = answer2;
                //printf("%lli %lli\n", answer1, answer2);
            }
            printf("Case #%hi: %s %s\n", caseNumber+1, newCoders, newJammers);
        }
    }

    exit(0);
}