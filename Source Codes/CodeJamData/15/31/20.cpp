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

int main() {
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\a_in.txt", "r", stdin);
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\a_out.txt", "w", stdout);
    int cs; scanf("%d", &cs);
    forint(fcs, 1, cs) {
        int ans = 0, R, C, W;
        scanf("%d%d%d", &R, &C, &W);
        if (C % W == 0) ans = C / W + W - 1;
        else ans = C / W + W;
        if (R > 1) ans += C / W * (R - 1);
        printf("Case #%d: %d\n", fcs, ans);
    }
	return 0;
}
