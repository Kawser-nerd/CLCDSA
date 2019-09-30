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

typedef long test_cases;
typedef long num_horses;

num_horses total, numRed, numOrange, numYellow, numGreen, numBlue, numViolet;
char answer[1001];

int main() {
    num_horses i;
    test_cases numTestCases, l;
    scanf("%li", &numTestCases);
    
    REPEAT(l, numTestCases) {
        scanf("%li %li %li %li %li %li %li", &total, &numRed, &numOrange, &numYellow, &numGreen, &numBlue, &numViolet);
        if ((numRed >= max(numYellow-numBlue, numBlue-numYellow)) && (numRed <= numYellow+numBlue)) {
           if (numYellow < numBlue) {
               REPEAT(i, numYellow) answer[2*i] = 'Y', answer[2*i+1] = 'B';
               REPEAT(i, numBlue-numYellow) answer[i+2*numYellow] = 'B';
           }
           else {
               REPEAT(i, numBlue) answer[2*i] = 'B', answer[2*i+1] = 'Y';
               REPEAT(i, numYellow-numBlue) answer[i+2*numBlue] = 'Y';
           }
           answer[numBlue+numYellow] = '\0';
           REPEAT(i, numRed) {
               PRINTF("A %s\n", answer);
               memmove(answer+(numBlue+numYellow-i), answer+(numBlue+numYellow-i-1), (2*i+2)*sizeof(char));
               answer[numBlue+numYellow-i-1] = 'R';
           }
           printf("Case #%li: %s\n", l+1, answer);
        }
        else printf("Case #%li: IMPOSSIBLE\n", l+1);
    }
    
    exit(0);
}