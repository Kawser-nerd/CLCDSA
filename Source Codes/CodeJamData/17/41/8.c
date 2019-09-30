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
typedef long num_people;
typedef long num_groups;
typedef long num_pieces;
typedef long modulo;

num_pieces packSize;
num_groups numGroups, partitionLengths[4], answer;
num_people groups[100];

int main() {
    num_groups i;
    test_cases numTestCases, l;
    modulo storeModulo;
    scanf("%li", &numTestCases);

    REPEAT(l, numTestCases) {
        scanf("%li %li", &numGroups, &packSize);
        memset(partitionLengths, 0, sizeof(partitionLengths));
        REPEAT(i, numGroups) {
            scanf("%li", groups+i);
            storeModulo = groups[i] % packSize;
            partitionLengths[storeModulo]++;
        }
        
        for (answer = 0; numGroups > 0; answer++) {
            if (partitionLengths[0] > 0) {
                partitionLengths[0]--;
                numGroups--;
            }
            else if ((partitionLengths[1] > 0) && (partitionLengths[packSize-1] > 0)) {
                partitionLengths[1]--;
                partitionLengths[packSize-1]--;
                numGroups -= 2;
            }
            else if (packSize == 4) {
                if (partitionLengths[2] > 1) {
                    partitionLengths[2] -= 2;
                    numGroups -= 2;
                }
                else {
                    for (storeModulo = 1; storeModulo < 4; storeModulo += 2) if ((partitionLengths[2] > 0) && (partitionLengths[storeModulo] > 1)) {
                        partitionLengths[2]--;
                        partitionLengths[storeModulo] -= 2;
                        numGroups -= 3;
                        break;
                    }
                    if (storeModulo >= 4) for (storeModulo = 1; storeModulo < 4; storeModulo++) if (partitionLengths[storeModulo] > 0) {
                        numGroups -= min(partitionLengths[storeModulo], 4);
                        partitionLengths[storeModulo] -= min(partitionLengths[storeModulo], 4);
                    }
                }
            }
            else if (partitionLengths[1] > 0) {
                numGroups -= min(partitionLengths[1], packSize);
                partitionLengths[1] -= min(partitionLengths[1], packSize);
            }
            else if (partitionLengths[packSize-1] > 0) {
                numGroups -= min(partitionLengths[packSize-1], packSize);
                partitionLengths[packSize-1] -= min(partitionLengths[packSize-1], packSize);
            }
        }
        printf("Case #%li: %li\n", l+1, answer);
    }
    
    exit(0);
}