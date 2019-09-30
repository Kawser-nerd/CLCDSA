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
#define LD long double
#define MP make_pair
#define VLD vector<LD>
#define SZ size()
#define REP(i,n) for( int i=0;i<int(n);++i)
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
vector < VLD > q;
LD value(const VI & val)
{
    LD v = 1;
    REP(i, val.SZ)
     v *= q[i][val[i]];
    return v;
}
void problem()
{
    int m, n;
    scanf("%d%d", &m, &n);
    q.clear();
    REP(i, n) {
        VLD v;
        REP(o, 4) {
            LD vv;
            scanf("%Lf", &vv);
            v += vv;
        }
        sort(ALL(v));
        reverse(ALL(v));
        q.push_back(v);
    }
    VI pos(n);
    priority_queue < pair < LD, VI > > pq;
    pq.push(MP(value(VI(n)), VI(n)));
    int left = m;
    LD acc = 0;
    set < VI > se;
    while (!pq.empty() && left) {
        pair < LD, VI > v = pq.top();
        pq.pop();
        if (se.count(v.second))
            continue;
        se.insert(v.second);
        ;
        FORE(e, v.second);
        ;
        LD cur = v.first;
        acc += cur;
        left--;
        VI vi = v.second;
        REP(i, n) {
            if (vi[i] == 3)
                continue;
            LD nv = cur;
            if (q[i][vi[i]] < 0.001) {
                vi[i]++;
                nv = value(vi);
            } else {
                nv /= q[i][vi[i]];
                vi[i]++;
                nv *= q[i][vi[i]];
            }
            ;
            pq.push(MP(nv, vi));
            vi[i]--;
        }
    }
    printf("%.9Lf\n", acc);
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
