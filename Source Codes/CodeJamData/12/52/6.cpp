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

int S;

int dy[] = {-1, 0, 1, 0, -1, 1};
int dx[] = {0, -1, 0, 1, -1, 1};

inline int low(int x) {
    if (x <= S) {
        return 1;
    } else {
        return 1 + x - S;
    }
}

inline int high(int x) {
    if (x >= S) {
        return 2 * S - 1;
    } else {
        return 2 * S - 1 - (S - x);
    }
}

bool in_boundary(int x, int y) {
    return x >= 1 && x <= 2 * S - 1 && y >= low(x) && y <= high(x);
}

bool on_wall(int x, int y) {
    return x == 1 || x == 2 * S - 1 || y == low(x) || y == high(x);
}

int wall_no(int x, int y) {
    if (x == 1) {
        return 0;
    } else if (x <= S && y == high(x)) {
        return 1;
    } else if (x > S && y == high(x)) {
        return 2;
    } else if (x == 2 * S - 1) {
        return 3;
    } else if (x > S && y == low(x)) {
        return 4;
    } else {
        return 5;
    }
}

void dfs(int x, int y, vector<PII>& result, set<PII>& visitable) {
    visitable.erase(MP(x, y));
    result.PB(MP(x, y));
    for (int d = 0; d < 6; ++d) {
        int cx = x + dx[d];
        int cy = y + dy[d];
        if (visitable.find(MP(cx, cy)) != visitable.end()) {
            dfs(cx, cy, result, visitable);
        }
    }
}

vector<PII> reach(int x, int y, set<PII>& visitable) {
    vector<PII> result;
    dfs(x, y, result, visitable);
    return result;
}

inline bool is_corner(int x, int y) {
    return (x == 1 || x == S || x == 2 * S - 1) && (y == 1 || y == S || y == 2 * S - 1) && (x != S || y != S);
}

bool is_ring;
bool is_fork;
bool is_bridge;

void check_structure(const vector<PII>& fields) {
    set<PII> in_structure;
    FORE (it, fields) {
        in_structure.insert(*it);
    }
    set<PII> neighbors;
    bool got_wall = false;
    int n_corners = 0;
    static bool has_walls[6];
    for (int i = 0; i < 6; ++i) {
        has_walls[i] = false;
    }
    FORE (it, fields) {
        for (int d = 0; d < 6; ++d) {
            int x = it->ST + dx[d];
            int y = it->ND + dy[d];
            if (in_boundary(x, y) && in_structure.find(MP(x, y)) == in_structure.end()) {
                neighbors.insert(MP(x, y));
            }
        }
        if (on_wall(it->ST, it->ND)) {
            got_wall = true;
            if (is_corner(it->ST, it->ND)) {
                ++n_corners;
            } else {
                has_walls[wall_no(it->ST, it->ND)] = true;
            }
        }
    }
    if (n_corners > 1) {
        is_bridge = true;
    }
    int n_walls = 0;
    for (int i = 0; i < 6; ++i) {
        n_walls += has_walls[i];
    }
    if (n_walls > 2) {
        is_fork = true;
    }
    bool first_it = true;
    while (!neighbors.empty()) {
        vector<PII> v = reach(neighbors.begin()->ST, neighbors.begin()->ND, neighbors);
        bool cur_wall = false;
        FORE (it, v) {
            if (on_wall(it->ST, it->ND)) {
                cur_wall = true;
            }
        }
        if (!cur_wall && (!first_it || !neighbors.empty())) {
            is_ring = true;
            break;
        }
        first_it = false;
    }
}

void go(set<PII>& got) {
    is_ring = false;
    is_fork = false;
    is_bridge = false;
    while (!got.empty()) {
        vector<PII> cur = reach(got.begin()->ST, got.begin()->ND, got);
        check_structure(cur);
    }
}

void print_result(int move) {
    bool hyp = false;
    if (is_bridge) {
        cout << "bridge";
        hyp = true;
    }
    if (is_fork) {
        if (hyp) {
            cout << "-";
        }
        cout << "fork";
        hyp = true;
    }
    if (is_ring) {
        if (hyp) {
            cout << "-";
        }
        cout << "ring";
    }
    cout << " in move " << move + 1 << endl;
}

void alg() {
    static int case_no = 0;
    cout << "Case #" << ++case_no << ": ";
    int n_moves;
    cin >> S >> n_moves;
    vector<PII> moves(n_moves);
    for (int i = 0; i < n_moves; ++i) {
        cin >> moves[i].ST >> moves[i].ND;
    }
    set<PII> s;
    for (int i = 0; i < n_moves; ++i) {
        s.insert(MP(moves[i].ST, moves[i].ND));
        set<PII> s2 = s;
        go(s2);
        if (is_ring || is_fork || is_bridge) {
            print_result(i);
            return;
        }
    }
    cout << "none\n";
}

int main() {
    int d;
    cin >> d;
    while (d--) {
        alg();
    }
}
