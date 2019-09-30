#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

struct Level {
    int length;
    int chance;
    int index;
};

bool operator < (const Level& a, const Level& b) {
    if (a.length * b.chance != b.length * a.chance) {
        return a.length * b.chance < b.length * a.chance;
    } else {
        return a.index < b.index;
    }
}

void alg() {
    int n;
    cin >> n;
    vector<Level> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].index = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].length;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].chance;
    }
    sort(ALL(v));
    static int case_no = 0;
    printf("Case #%d:", ++case_no);
    FORE (it, v) {
        printf(" %d", it->index);
    }
    printf("\n");
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        alg();
    }
}
