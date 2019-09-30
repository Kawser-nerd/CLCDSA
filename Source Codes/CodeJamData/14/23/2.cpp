#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string.h>
#include <queue>
#include <cstdio>
#include <cassert>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> color;
vector< vector<int> > g;
vector<bool> used;
int n;
vector<string> code;

void dfsGreyWhite(int v) {
    if (color[v] == 2) return;
    used[v] = true;
    forv(i, g[v]) {
        int u = g[v][i];
        if (!used[u]) dfsGreyWhite(u);
    }
}

bool checkInv(int s) {
    used = vector<bool>(n, false);
    dfsGreyWhite(s);
    forn(i, n) if (color[i] == 0 && !used[i]) return false;
    return true;
}

void solve(int tc) {
    cerr << tc << endl;
    cout << "Case #" << tc << ": ";
    int m;
    cin >> n >> m;
    color = vector<int>(n, 0);
    code = vector<string>(n);
    g = vector< vector<int> >(n);
    forn(i, n) cin >> code[i];
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        v--, u--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int s = 0;
    forn(i, n) if (code[i] < code[s]) s = i;
    vector<int> p(n, -1);
    color[s] = 1;
    string ans = code[s];
    int cur = s;
    forn(it, n - 1) {
        int up = 0;
        int next = -1;
        vector<int> tmpColor = color;
        int v = cur;
        int bestUp = -1;
        while (v != -1) {
            if (!checkInv(s)) break;
            forv(i, g[v]) {
                int u = g[v][i];
                if (color[u] == 0 && (next == -1 || code[next] > code[u])) {
                    next = u; 
                    bestUp = up;
                }
            }
            color[v] = 2;
            v = p[v];
            up++;
        }
        if (next == -1) throw;
        color = tmpColor;
        v = cur;
        forn(i, bestUp) {
            color[v] = 2;
            v = p[v];
        }
		p[next] = v;
        color[next] = 1;
        cur = next;
        ans += code[next];
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    forn(i, tc) solve(i + 1);
    return 0;
}
