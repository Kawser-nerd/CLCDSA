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

void alg() {
    int n;
    cin >> n;
    int K;
    cin >> K;
    vector<LD> v;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        char ch;
        cin >> a >> ch >> b >> c;
        for (int j = 0; j < c; ++j) {
            v.PB(a / (LD) b);
        }
    }
    n = (int) v.size();
    sort(ALL(v));
    reverse(ALL(v));
    vector<LD> pref_sums(n + 1);
    vector<LD> pref_mul(n + 1);
    {
        pref_sums[0] = 1;
        pref_mul[0] = 1;
        for (int i = 1; i <= n; ++i) {
            LD p = v[i - 1];
            pref_sums[i] = pref_sums[i - 1] * (1 - p) + pref_mul[i - 1] * p;
            pref_mul[i] = pref_mul[i - 1] * p;
        }
    }
    vector<LD> suf_sums(n + 1);
    vector<LD> suf_mul(n + 1);
    {
        suf_sums[0] = 1;
        suf_mul[0] = 1;
        for (int i = 1; i <= n; ++i) {
            LD p = v[n - i];
            suf_sums[i] = suf_sums[i - 1] * p + suf_mul[i - 1] * (1 - p);
            suf_mul[i] = suf_mul[i - 1] * (1 - p);
        }
    }
    LD result = 1;
    for (int i = 0; i <= K; ++i) {
        LD cur = pref_sums[i] * suf_mul[K - i] + pref_mul[i] * suf_sums[K - i] - pref_mul[i] * suf_mul[K - i];
        result = min(result, 1 - cur);
    }
    printf("%.9Lf\n", result);
    fflush(stdout);
}

int main() {
    int d;
    cin >> d;
    for (int case_no = 1; case_no <= d; ++case_no) {
        cout << "Case #" << case_no << ": ";
        alg();
    }
}
