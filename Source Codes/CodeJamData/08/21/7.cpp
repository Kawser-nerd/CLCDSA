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
bool ok(PI a, PI b, PI c)
{
    return ((a.first + b.first + c.first) % 3 == 0) &&
           ((a.second + b.second + c.second) % 3 == 0);
}
ll c2(ll a)
{
    return a * (a - 1) / 2;
}
ll c3(ll a)
{
    return a * (a - 1) / 2 * (a - 2) / 3;
}
int main() {
    int t; scanf("%d", &t);
    REP(sd,t)
    {
        int n, a, b, c, d, x0, y0, m;
        scanf("%d %d %d %d %d %d %d %d", &n, &a, &b, &c, &d, &x0, &y0, &m);
        vector<long long> x(1, x0), y(1, y0);
        for (int i=1; i<n; i++)
        {
            x.push_back((a * x.back() + b) % m);
            y.push_back((c * y.back() + d) % m);
        }

        map<PI, int> poc;
        REP(i,n) poc[PI(x[i] % 3, y[i] % 3)]++;

        long long res = 0;
        FOREACH(i1,poc) FOREACH(i2,poc) if (i2->first >= i1->first) FOREACH(i3,poc) if (i3->first >= i2->first)
            if (ok(i1->first, i2->first, i3->first))
        {
            if (i2->first != i1->first && i3->first != i2->first) res += ll(i1->second) * i2->second * i3->second;
            else if (i2->first == i1->first && i3->first != i2->first)
                res += c2(i1->second) * i3->second;
            else if (i2->first != i1->first && i3->first == i2->first)
                res += c2(i2->second) * i1->second;
            else if (i2->first == i1->first && i3->first == i2->first)
                res += c3(i2->second);
        }
        printf("Case #%d: %lld\n", sd+1, res);
    }
}
