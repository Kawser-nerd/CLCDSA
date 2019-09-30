#include <iostream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>
#include <deque>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#include <algorithm>
#include <numeric>

#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) ((x) * (x))
#define len(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'

#ifdef CUTEBMAING
#include "cutedebug.h"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(x) 42
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

const int inf = ((1 << 30) - 1);
const int64 linf = ((1ll << 62) - 1);
const int N = 40;

int ra, rb, rk;
int a[N], b[N], k[N];

int64 dp[N + 1][2][2][2];

void solve(){
    cin >> ra >> rb >> rk;
    for (int i = 0; i < N; i++){
        a[N - i - 1] = ra % 2, ra /= 2;
        b[N - i - 1] = rb % 2, rb /= 2;
        k[N - i - 1] = rk % 2, rk /= 2;
    }
    for (int i = 0; i <= N; i++)
        for (int j = 0; j < 2; j++)
            for (int z = 0; z < 2; z++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][z][l] = 0;
    dp[0][0][0][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 2; j++)
            for (int z = 0; z < 2; z++)
                for (int l = 0; l < 2; l++){
                    int mx1 = j ? 1 : a[i], mx2 = z ? 1 : b[i], mx3 = l ? 1 : k[i];
                    for (int x = 0; x <= mx1; x++)
                        for (int y = 0; y <= mx2; y++)
                            if ((x & y) <= mx3){
                                int ni = i + 1, nj = j || a[i] != x, nk = z || b[i] != y, nl = l || k[i] != (x & y);
                                dp[ni][nj][nk][nl] += dp[i][j][z][l];
                            }
                }
    cout << dp[N][1][1][1] << endl;
}

int main(){
#if defined CUTEBMAING && !defined STRESS
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif
    int testCasesCount = 0;
    cin >> testCasesCount;
    for (int i = 1; i <= testCasesCount; i++){
        printf("Case #%d: ", i);
        double begin = clock();
        solve();
        double end = clock();
        eprintf("Test %d: %.3lf seconds\n", i, (end - begin) / CLOCKS_PER_SEC);
    }
    return 0;
}
