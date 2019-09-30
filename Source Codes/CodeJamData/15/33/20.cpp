#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
using namespace std;
#pragma warning(disable: 4996)

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

// ------------------------ template ends here ------------------------ //

int C, D, V, ans, d[99];

void go() {
    ans = 0;
    
    int ind = 1;
    LL cur = 0;
    while (cur < (LL)V) {
        if (ind <= D && d[ind] <= cur + 1) {
            cur += LL(d[ind]) * LL(C);
            ++ind;
            continue;
        }
        ++ans;
        cur += LL(cur + 1) * LL(C);
    }
}

int main() {
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\c_in.txt", "r", stdin);
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\c_out.txt", "w", stdout);
    int cs; scanf("%d", &cs);
    forint(fcs, 1, cs) {

        ans = 999;
        scanf("%d%d%d", &C, &D, &V);
        forint(i, 1, D) scanf("%d", &d[i]);

        go();

        printf("Case #%d: %d\n", fcs, ans);
    }
	return 0;
}
