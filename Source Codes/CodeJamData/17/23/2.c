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
typedef long city;
typedef long num_cities;
typedef long dist;
typedef double time;
typedef long num_queries;

city start, end;
dist horseEndurances[100], horseSpeeds[100], dists[100][100], endurancesLeft[100][100];
num_cities numCities;
num_queries numQueries;
time answers[100], timesFromStart[100][100];
bool visited[100][100];

int main() {
    num_cities i, j, horse, storeI, storeHorse;
    num_queries m;
    time minTime;
    test_cases numTestCases, l;
    scanf("%li", &numTestCases);

    REPEAT(l, numTestCases) {
        scanf("%li %li", &numCities, &numQueries);
        REPEAT(i, numCities) scanf("%li %li", horseEndurances+i, horseSpeeds+i);
        REPEAT(i, numCities) REPEAT(j, numCities) scanf("%li", dists[i]+j);
        
        printf("Case #%li: ", l+1);
        REPEAT(m, numQueries) {
            scanf("%li %li", &start, &end);
            start--, end--;
            REPEAT(i, numCities) REPEAT(horse, numCities) timesFromStart[i][horse] = -1, visited[i][horse] = false;
            timesFromStart[start][start] = 0, endurancesLeft[start][start] = horseEndurances[start];
            
            while (true) {
                minTime = -1;
                REPEAT(i, numCities) REPEAT(horse, numCities) if (!visited[i][horse] && (timesFromStart[i][horse] >= 0) && ((minTime < 0) || (timesFromStart[i][horse] < minTime))) {
                    storeI = i, storeHorse = horse;
                    minTime = timesFromStart[i][horse];
                }
                PRINTF("S %li %li\n", storeI, storeHorse);
                if (visited[storeI][storeHorse]) break;
                visited[storeI][storeHorse] = true;
                
                REPEAT(j, numCities) if (dists[storeI][j] >= 0) {
                    if (dists[storeI][j] <= endurancesLeft[storeI][storeHorse]) {
                        minTime = timesFromStart[storeI][storeHorse]+((double)dists[storeI][j])/horseSpeeds[storeHorse];
                        if ((timesFromStart[j][storeHorse] < 0) || (timesFromStart[j][storeHorse] > minTime)) {
                            timesFromStart[j][storeHorse] = minTime;
                            endurancesLeft[j][storeHorse] = endurancesLeft[storeI][storeHorse]-dists[storeI][j];
                        }
                    }
                    if (dists[storeI][j] <= horseEndurances[storeI]) {
                        minTime = timesFromStart[storeI][storeHorse]+((double)dists[storeI][j])/horseSpeeds[storeI];
                        if ((timesFromStart[j][storeI] < 0) || (timesFromStart[j][storeI] > minTime)) {
                            timesFromStart[j][storeI] = minTime;
                            endurancesLeft[j][storeI] = horseEndurances[storeI]-dists[storeI][j];
                        }
                    }
                }
            }
            minTime = -1;
            REPEAT(horse, numCities) if ((timesFromStart[end][horse] >= 0) && ((minTime < 0) || (timesFromStart[end][horse] < minTime))) minTime = timesFromStart[end][horse];
            printf("%.7f%c", minTime, (m+1 == numQueries) ? '\n' : ' ');
        }
    }
    
    exit(0);
}