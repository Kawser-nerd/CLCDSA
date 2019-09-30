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
vector<int> w;
int sef(int a) {
    if (w[a]<0) return a;
    return w[a]=sef(w[a]);
}
bool spoj(int a, int b) {
    int x=sef(a), y=sef(b);
    if (x==y) return false;
    if (w[x]>w[y]) swap(x, y);
    w[x]+=w[y]; w[y]=x;
    return true;
}
int main() {
    int t; scanf("%d", &t);
    REP(sd,t)
    {
        ll a, b, p;
        scanf("%lld %lld %lld", &a, &b, &p);
        w.assign(b - a + 1, -1);

        vector<bool> q(1000010, true); q[0] = q[1] = false;
        for (ll i=2; i<=b; i++) if (q[i])
        {
            if (i >= q.size() || i > b - a + 5) break;
            for (ll j = 2 * i; j < q.size(); j += i) q[j] = false;
            if (i >= p)
            {
                vector<int> y;
                for (ll j = (a / i) * i; j <= b; j += i) if (j >= a && j >= i)
                    y.push_back(j);

                for (unsigned j=1; j<y.size(); j++)
                    spoj(y[0] - a, y[j] - a);
            }
        }

        int poc = 0;
        REP(i,w.size()) if (w[i] < 0) poc++;
        printf("Case #%d: %d\n", sd+1, poc);
    }
}
