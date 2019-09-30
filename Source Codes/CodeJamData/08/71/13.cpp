#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <math.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define REP(i,n) for( int i=0;i<int(n);++i)
#define SZ size()
#define VS vector<string>
#define VI vector<int>
namespace my_namespace {
    template <class X >static vector < X > &operator+=(vector < X > &vec,
     const X & el) {
        vec.push_back(el);
        return vec;
}};
#define VALT(c) __typeof(*(c).begin())
#define ITER(c) __typeof((c).begin())
#define FORE(e,c) for( ITER(c) it_##e = (c).begin(), it2_##e = it_##e; it_##e!=(c).end() && it_##e==it2_##e; ++it_##e) for( VALT(c) e = *it_##e; it2_##e==it_##e; it2_##e++)
using namespace my_namespace;
int N;
map < string, VS > ma;
int rec(const string & s)
{
    VS & cld = ma[s];
    int ret = (int) cld.SZ + 1;
    VI res;
    FORE(e, cld)
     res += rec(e);
    sort(ALL(res));
    reverse(ALL(res));
    REP(i, res.SZ)
     res[i] += i;
    FORE(e, res)
     ret = max(ret, e);
    return ret;
}
void problem()
{
    scanf("%d", &N);
    ma.clear();
    string root;
    REP(i, N) {
        char b[30];
        scanf("%s", b);
        string s(b);
        if (!i)
            root = s;
        int t;
        scanf("%d", &t);
        ma[s] = VS();
        REP(i, t) {
            scanf("%s", b);
            string ss(b);
            if (islower(ss[0]))
                continue;
            ma[s] += ss;
        }
    }
    printf("%d\n", rec(root));
}
int main()
{
    int n;
    scanf("%d", &n);
    REP(i, n) {
        printf("Case #%d: ", i + 1);
        problem();
    }
    return 0;
}
