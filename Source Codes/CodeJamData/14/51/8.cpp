// Rain Dreamer MODEL
// Create @ 22:11 06-14 2014
// Comment - 

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define RD(x) freopen (x, "r", stdin)
#define WT(x) freopen (x, "w", stdout)
#define clz(x) memset (x, 0, sizeof(x))
#define cln(x) memset (x, -1, sizeof(x))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int MAXN = 1000000 + 10;

int n, p, q, r, s;
int64 a[MAXN], sum[MAXN];

int check_ans(int x, int y, int64& max_ch) {
    for (int off = -2; off <= 2; off += 1) {
        int t1 = x, t2 = y + off;
        if (t2 < t1 || t2 >= n) continue ;
        //printf ("test %d %d\n", t1, t2);
        int64 max_t = max(sum[t1], max(sum[t2] - sum[t1], sum[n] - sum[t2])); 
        if (sum[n] - max_t > max_ch) {
            max_ch = sum[n] - max_t;
        }
    }
}

double solve() {
    if (n == 1) {
        return 0;
    }
    rep (i, n) {
        a[i] = ((int64)i * p + q) % r + s;
        //printf ("%I64d ", a[i]);
        sum[i + 1] = sum[i] + a[i];
    }
    
    if (n == 2) {
        return 1.0 * min(a[0], a[1]) / sum[2];
    }
    
    int64 tot = sum[n], max_ch = 0;
    repf (i, 1, n) {
        int64 left = tot - sum[i];
        int id = upper_bound(sum + i + 1, sum + n + 1, sum[i] + left / 2) - sum;
        check_ans(i, id, max_ch);
        
        id = lower_bound(sum + i + 1, sum + n + 1, sum[i] + left / 2) - sum;
        check_ans(i, id, max_ch);
    }
    return 1.0 * max_ch / tot;
}

int main() {
    WT ("A.out");
    
    repcase {
        scanf ("%d%d%d%d%d", &n, &p, &q, &r, &s);
        printf ("Case #%d: %.10lf\n", Case++, solve());
    }
    return 0;
}

