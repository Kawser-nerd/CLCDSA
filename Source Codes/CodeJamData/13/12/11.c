#include <stdio.h>
#define MAX_ACTIVITIES 12
#define MAX_ENERGY 7
#define MIN(A,B) ((A) < (B) ? (A) : (B))

int cache[MAX_ENERGY][MAX_ACTIVITIES];
int seen[MAX_ENERGY][MAX_ACTIVITIES];

int tests;

int activities[MAX_ACTIVITIES];
int n_activities;
int regain;
int energy;

int dp(int energy_left, int upto);

int main(int argc, char* argv[]) {
    scanf("%d", &tests);
    int i;
    for (i = 0; i < tests; i++) {
        int j;
        for (j = 0; j < MAX_ENERGY; j++) {
            int k;
            for (k = 0; k < MAX_ACTIVITIES; k++) {
                seen[j][k] = 0;
            }
        }
        scanf("%d %d %d", &energy, &regain, &n_activities);
        
        for (j = 0; j < n_activities; j++) {
            scanf("%d", &activities[j]);
        }
        printf("Case #%d: %d\n", i+1, dp(energy, 0));
    }
    return 0;
}

int dp(int energy_left, int upto) {
    if (upto >= n_activities) {
        return 0;
    }
    if (seen[energy_left][upto]) {
        return cache[energy_left][upto];
    }
    seen[energy_left][upto] = 1;
    
    int level;
    int best = 0;
    for (level = 0; level <= energy_left; level++) {
        
        int cur = dp(MIN(energy_left-level+regain, energy), upto+1)
            + level*activities[upto];
        
        if (cur > best) {
            best = cur;
        }
    }
    cache[energy_left][upto] = best;
    return best;
}
