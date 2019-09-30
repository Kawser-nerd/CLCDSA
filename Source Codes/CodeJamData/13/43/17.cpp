#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 2048;


int n, a[MAXN], b[MAXN];


void read() {
    cin >> n;
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        cin >> b[i];
}


vector<int> g[MAXN], gi[MAXN];
bitset<MAXN> r[MAXN], ri[MAXN];
bool u[MAXN], ui[MAXN];

void add_edge(int a, int b) {
    g[a].push_back(b);
    gi[b].push_back(a);
}

const bitset<MAXN>& get_r(int v) {
    if (u[v])
        return r[v];
    u[v] = true;
    r[v].reset();

    forn(i, g[v].size()) {
        int to = g[v][i];
        r[v] |= get_r(to);
        r[v].set(to);
    }

    return r[v];
}

const bitset<MAXN>& get_ri(int v) {
    if (ui[v])
        return ri[v];
    ui[v] = true;
    ri[v].reset();

    forn(i, gi[v].size()) {
        int to = gi[v][i];
        ri[v] |= get_ri(to);
        ri[v].set(to);
    }

    return ri[v];
}

void solve() {
    forn(i, n) {
        g[i].clear();
        gi[i].clear();
    }
    forn(i, n) {
        for (int j = i - 1; j >= 0; --j)
            if (a[j] == a[i] - 1) {
                add_edge(i, j);
                break;
            }
        for (int j = i - 1; j >= 0; --j)
            if (a[j] == a[i]) {
                add_edge(j, i);
                break;
            }
    }
    ford(i, n) {
        for (int j = i + 1; j < n; ++j)
            if (b[j] == b[i] - 1) {
                add_edge(i, j);
                break;
            }
        for (int j = i + 1; j < n; ++j)
            if (b[j] == b[i]) {
                add_edge(j, i);
                break;
            }
    }

    memset(u, 0, sizeof u);
    memset(ui, 0, sizeof ui);
    bitset<MAXN> already;
    vector<int> ans(n);
    forn(i, n) {
        const bitset<MAXN>& cur = get_r(i);
        const bitset<MAXN>& curi = get_ri(i);
        bitset<MAXN> incomp = already & ~(cur | curi);

        int smaller_cnt = (int)cur.count();
        int incomp_cnt = (int)incomp.count();
        ans[i] = smaller_cnt + incomp_cnt + 1;
        if (ans[i] < 1 || ans[i] > n)
            throw;

        already.set(i);
    }

    forn(i, n)
        cout << ' ' << ans[i];
    cout << endl;

    sort(all(ans));
    if (unique(all(ans)) != ans.end())
        throw;
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	forn(tt, ts) {
		read();
		if (!cin)  throw;
		printf("Case #%d:", tt + 1);
		solve();
	}
}
