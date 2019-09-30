#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); ++i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> PI;
int t[1<<21], s;
void pridaj(int ind, int co)
{
    ind += s;
    while (ind > 0)
    {
        t[ind] += co;
        ind /= 2;
    }
}
int hladaj(int co)
{
    int ind = 1;
    while (ind < s)
    {
        ind *= 2;
        if (t[ind] < co)
            co -= t[ind++];
    }
    return ind - s;
}
int main() {
    int tt; scanf("%d", &tt);
    REP(sd,tt)
    {
        int k, n;
        scanf("%d %d", &k, &n);
        vector<int> d(n);
        map<int, int> q, res;
        REP(i,n)
        {
            scanf("%d", &d[i]);
            q[d[i] - 1] = i;
        }
        memset(t, 0x00, sizeof(t));

        s = 1;
        while (s < k) s *= 2;
        REP(i,k) pridaj(i, 1);

        int u = 0;
        vector<int> por, in(k);
        REP(i,k)
        {
            u = (u + i) % (k - i);
            int co = hladaj(u + 1);
            if (q.count(co))
                res[co] = i + 1;
            por.push_back(co);
            pridaj(co, -1);
        }
        REP(i,k) in[por[i]] = i;

        printf("Case #%d:", sd+1);
        REP(i,n) printf(" %d", res[d[i]-1]);
        printf("\n");
    }
}
