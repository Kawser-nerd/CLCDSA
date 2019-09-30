#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl

int v[50][2];

bool visited[(1 << 10) + 5][10];
int n;
int steps;

void alg() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> v[i][0] >> v[i][1];
        --v[i][0];
        --v[i][1];
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }
    steps = 0;
    int x = 0;
    int mask = 0;
    while (true) {
        if (x == n - 1) {
            cout << steps << endl;
            return;
        }
        if (visited[mask][x]) {
            cout << "Infinity" << endl;
            return;
        }
        visited[mask][x] = true;
        ++steps;
        int nmask = mask ^ (1 << x);
        x = v[x][(mask >> x) & 1];
        mask = nmask;
    }
}

int main() {
    int d;
    cin >> d;
    for (int case_no = 1; case_no <= d; ++case_no) {
        cout << "Case #" << case_no << ": ";
        alg();
    }
}
