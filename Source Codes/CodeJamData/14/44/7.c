#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1010
#define MOD 1000000007
#define inf (-(1LL << 60))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

struct Pair{
    long long int val, counter;
};

char str[8][12];
bool visited[1 << 8][4];
struct Pair dp[1 << 8][4];
int t, n, lim, m, cost[1 << 8], ar[MAX][26];

int getCost(int bitmask){
    int i, j, k, r, idx = 1;

    clr(ar);
    for (i = 0; i < n; i++){
        if (bitmask & (1 << i)){
            r = 0;
            for (j = 0; str[i][j] != 0; j++){
                int x = str[i][j] - 'A';
                if (!ar[r][x]){
                    ar[r][x] = idx;
                    r = idx++;
                }
                else r = ar[r][x];
            }
        }
    }

    return idx;
}

struct Pair F(int bitmask, int r){
    if (r == m){
        struct Pair temp;
        temp.val = 0, temp.counter = 1;
        if (bitmask == lim) return temp;
        temp.val = inf, temp.counter = 0;
        return temp;
    }
    if (visited[bitmask][r]) return dp[bitmask][r];

    struct Pair res;
    res.val = inf, res.counter = 0;

    int i, j, d = 0, T[8];
    for (i = 0; i < n; i++){
        if (!(bitmask & (1 << i))) T[d++] = i;
    }

    int tlim = (1 << d) - 1;
    for (i = 1; i <= tlim; i++){
        int cbitmask = 0;
        int nbitmask = bitmask;
        for (j = 0; j < d; j++){
            if (i & (1 << j)){
                nbitmask |= (1 << T[j]);
                cbitmask |= (1 << T[j]);
            }
        }

        struct Pair x = F(nbitmask, r + 1);
        x.val += cost[cbitmask];
        if (x.val > res.val) res.val = x.val, res.counter = x.counter;
        else if (x.val == res.val) res.counter = (res.counter + x.counter) % MOD;
    }

    visited[bitmask][r] = true;
    return (dp[bitmask][r] = res);
}

int main(){
    read();
    write();
    int T = 0, i, j, k, bitmask;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++) scanf("%s", str[i]);
        lim = (1 << n) - 1;

        for (bitmask = 0; bitmask <= lim; bitmask++){
            cost[bitmask] = getCost(bitmask);
        }

        clr(visited);
        struct Pair res = F(0, 0);
        printf("Case #%d: %lld %lld\n", ++T, res.val, res.counter);
    }
    return 0;
}
