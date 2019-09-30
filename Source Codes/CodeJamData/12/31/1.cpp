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

const int N = 1005;

bool visited[N];
vector<int> e[N];
int n;

bool diamond;

void dfs(int x) {
    if (visited[x]) {
        diamond = true;
        return;
    }
    visited[x] = true;
    FORE (it, e[x]) {
        dfs(*it);
    }
}

void alg() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int deg;
        scanf("%d", &deg);
        for (int j = 1; j <= deg; ++j) {
            int a;
            scanf("%d", &a);
            e[a].PB(i);
        }
    }
    diamond = false;
    for (int i = 1; i <= n && !diamond; ++i) {
        for (int j = 1; j <= n; ++j) {
            visited[j] = false;
        }
        dfs(i);
    }
    static int case_no = 0;
    printf("Case #%d: %s\n", ++case_no, diamond ? "Yes" : "No");
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        alg();
    }
}
