#define _ijps 01
#define _CRT_SECURE_NO_DEPRECATE
//#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h> 
#include <list>
#include <cstring>
#include <queue>
using namespace std;

#define name ""
#define times clock() * 1.0 / CLOCKS_PER_SEC

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

struct __isoff {
    __isoff() {
        if(_ijps)
            freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
        //else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
        //ios_bsume::sync_with_stdio(0);
        //srand(time(0));
        srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
    }
    ~__isoff() {
        //if(_ijps) cout<<times<<'\n';
    }
} __osafwf;
const ull p1 = 131;
const ull p2 = 129;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int infi = 1e9 + 7;
const ll inf = 1e18 + 7;
const ll dd = 5e5 + 7;

typedef long long ll;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, a, n) for(int i = a; i < n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

const int all_time = 24 * 60;

int main() {
    int t;
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
        int a, b;
        cin >> a >> b;
        vector<int> C(all_time + 1, 3);
        for(int i = 0; i < a; i++) {
            int l, r;
            cin >> l >> r;
            l++, r++;
            for(int j = l; j < r; j++) {
                C[j] = 1;
            }
        }
        for(int i = 0; i < b; i++) {
            int l, r;
            cin >> l >> r;
            l++, r++;
            for(int j = l; j < r; j++) {
                C[j] = 2;
            }
        }
        vector<vector<int> > dp[2];
        int res = infi;
        for(int e = 0; e < 2; e++) {
            for(int i = 0; i < 2; i++) {
                dp[i].assign(all_time + 2, vector<int>(all_time / 2 + 2, infi));
            }
            dp[e][0][0] = 0;
            for(int i = 1; i <= all_time; i++) {
                for(int j = 0; j < 2; j++) {
                    if(C[i] & (1 << j)) {
                        for(int k = 0; k < all_time / 2 + 1; k++) {
                            for(int z = 0; z < 2; z++) {
                                if(k - j >= 0) {
                                    dp[j][i][k] = min(dp[j][i][k], dp[z][i - 1][k - j] + (z != j));
                                }
                            }
                        }
                    }
                }
            }
            for(int t = 0; t < 2; t++) {
                res = min(res, dp[t][all_time][all_time / 2] + (t != e));
            }
        }
        cerr << ii << '\n';
        printf("Case #%d: %d\n", ii, res);
    }
}