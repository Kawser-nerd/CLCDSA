// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os;
}

template<typename T> ostream& operator << (ostream& os, const vector<T>& v) {
    os << "["; FORE(i, v) { if (i != v.begin()) os << ", "; os << *i; } os << "]"; return os;
}

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

int n;
VI C;
VVI G;
VI path;

bool find_path(int x, int p, int g) {
    if (x == g) {
        path.push_back(x);
        return true;
    }
    FORE(i, G[x]) if (*i != p && find_path(*i, x, g)) {
        path.push_back(x);
        return true;
    }
    return false;
}

vector<bool> on_path;

int max_path(int x, int p) {
    int res = 0;
    FORE(i, G[x]) if (*i != p)
        res = max(res, max_path(*i, x));
    return res + C[x];
}

int turn_a(int, int);
int turn_b(int, int);

int turn_a(int pos_a, int pos_b) {
    int res = -INF;
    if (pos_a != pos_b) {
        if (pos_a < pos_b) {
            res = max(res, turn_b(pos_a + 1, pos_b));
        } else {
            res = max(res, turn_b(pos_a - 1, pos_b));
        }
    }

    VI MP;
    FORE(i, G[path[pos_a]]) if (!on_path[*i])
        MP.push_back(max_path(*i, path[pos_a]));
    sort(MP.rbegin(), MP.rend());

    int best_a = 0;
    if (SIZE(MP) >= 1)
        best_a = max(best_a, MP[0]);

    int worst_b = 0, sum = 0;
    int i = pos_b;
    while (i != pos_a) {
        sum += C[path[i]];
        worst_b = max(worst_b, sum);
        FORE(j, G[path[i]]) if (!on_path[*j])
            worst_b = max(worst_b, sum + max_path(*j, path[i]));
        if (i > pos_a) {
            --i;
        } else {
            ++i;
        }
    }
    if (SIZE(MP) >= 2)
        worst_b = max(worst_b, sum + MP[1]);

    res = max(res, best_a - worst_b);

    return res + C[path[pos_a]];
}

int turn_b(int pos_a, int pos_b) {
    return -turn_a(pos_b, pos_a);
}

int solve(int start_a, int start_b) {
    path.clear();
    assert(find_path(start_b, -1, start_a));
    on_path.clear();
    on_path.resize(n, false);
    FORE(i, path)
        on_path[*i] = true;

    return turn_a(0, SIZE(path) - 1);
}

int main() {
    int t;
    scanf("%d", &t);
    FOR(ti, 1, t) {
        scanf("%d", &n);
        C.clear();
        C.resize(n);
        REP(i, n)
            scanf("%d", &C[i]);
        G.clear();
        G.resize(n);
        REP(i, n - 1) {
            int j;
            scanf("%d", &j);
            --j;
            G[i].push_back(j);
            G[j].push_back(i);
        }

        int res = -INF;
        REP(i, n) {
            int worst = INF;
            REP(j, n)
                worst = min(worst, solve(i, j));
            res = max(res, worst);
        }

        printf("Case #%d: %d\n", ti, res);
    }
}
