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
#define COND(p) if( p)
#define RESET(a,uch) memset( a, uch, sizeof( a))
#define IN(x,upper) ((x)>=0 && (x)<(upper))
#define REP(i,n) for( int i=0;i<int(n);++i)
namespace my_namespace {
};
#define FOR(i,p,k) for( int i=p; i<int(k); ++i)
using namespace my_namespace;
int mem[1 << 16][16];
int r, c;
bool brute(int mask, int pos)
{
    ;
    int &v = mem[mask][pos];
    if (v != -1)
        return (bool) v;
    int rr = pos / 4;
    int cc = pos % 4;
    FOR(i, rr - 1, rr + 2) FOR(j, cc - 1, cc + 2) COND((rr != i || cc != j) &&
     IN(i, r)
     && IN(j, c)) {
        int id = i * 4 + j;
        if (mask & 1 << id)
            continue;
        int nm = mask | 1 << id;
        if (!brute(nm, id))
            return v = true;
    }
    return v = false;
}
void problem()
{
    scanf("%d%d", &r, &c);
    RESET(mem, -1);
    int mask = 0;
    int pos;
    REP(i, r) {
        char b[20];
        scanf("%s", b);
        REP(j, c) {
            int id = i * 4 + j;
            if (b[j] != '.')
                mask |= 1 << id;
            if (b[j] == 'K')
                pos = id;
        }
    }
    ;
    printf("%s\n", brute(mask, pos) ? "A" : "B");
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
