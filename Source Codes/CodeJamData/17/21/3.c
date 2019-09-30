#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REPEAT(token, num) for (token = 0; token < num; token++)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
static inline long long min(long long length1, long long length2) { return (length1 < length2) ? length1 : length2; }
static inline long long max(long long length1, long long length2) { return (length1 > length2) ? length1 : length2; }

//#define DEBUG
#ifdef DEBUG
#define PRINTF printf
#else
#define PRINTF(...) 1
#endif

typedef long dist;
typedef long time;
typedef long num_horses;
typedef long test_cases;

dist destination, startingPoint, speed;
num_horses numOthers;
double answerTime;
static inline double divide(int int1, int int2) { return ((double)int1)/((double)int2); }

int main() {
    num_horses i;
    test_cases numTestCases, l;
    double storeTime;
    scanf("%li", &numTestCases);

    REPEAT(l, numTestCases) {
        scanf("%li %li", &destination, &numOthers);
        REPEAT(i, numOthers) {
            scanf("%li %li", &startingPoint, &speed);
            storeTime = divide(destination-startingPoint, speed);
            if (!i || (storeTime > answerTime)) answerTime = storeTime;
        }
        printf("Case #%li: %.7f\n", l+1, ((double)destination)/answerTime);
    }
    
    exit(0);
}