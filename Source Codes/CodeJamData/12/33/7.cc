#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long numA[1005], numB[1005];
int typA[1005], typB[1005];


long long cache[1005][1005];
bool seen[1005][1005];

int n, m;


long long solve(int a, int b) {
    if (a == n || b == m) return 0;
    if (seen[a][b]) return cache[a][b];
    seen[a][b] = true;

    int i, j;

    //skip this one for A?
    cache[a][b] = max(cache[a][b], solve(a+1, b));
    //skip this one for B?
    cache[a][b] = max(cache[a][b], solve(a, b+1));

    long long sumA = 0, sumB = 0;
    
    //we can assume they're the same type now..
    for (i = a; i < n; i++) {
        if (typA[i] == typA[a]) sumA += numA[i];
        sumB = 0;
        for (j = b; j < m; j++) {
            if (typB[j] == typA[a]) sumB += numB[j];
            cache[a][b] = max(cache[a][b], min(sumA, sumB) + solve(i+1, j+1));
        }
    }

    return cache[a][b];
}


long long brute(int a, int b, long long  usedA, long long  usedB) {
    if (a == n || b == m) return 0;

    long long sum = 0;
    long long ans = 0;
    if (typA[a] == typB[b]) {
        sum = min(numA[a] - usedA, numB[b] - usedB);
        usedA += sum;
        usedB += sum;
    }
    ans = max(ans, sum + brute(a+1, b, 0, usedB));
    ans = max(ans, sum + brute(a, b+1, usedA, 0));
    return ans;
}

int main() {
    int t = 1, T;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {

        memset(cache, 0, sizeof(cache));
        memset(seen, 0, sizeof(seen));
        scanf("%d %d", &n, &m);
        int i;
        for (i = 0; i < n; i++) scanf("%lld %d", &numA[i], &typA[i]);
        for (i = 0; i < m; i++) scanf("%lld %d", &numB[i], &typB[i]);

        fprintf(stderr, "Case #%d\n", t);
        printf("Case #%d: %lld\n", t, solve(0, 0));
        //printf("Case #%d: %lld\n", t, brute(0, 0,0,0));

    }
    return 0;
}

