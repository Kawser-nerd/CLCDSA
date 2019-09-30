#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <sys/time.h>
using namespace std;

#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef pair<ll, int> P;
typedef complex<double> comp;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const ll inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n, m;
ll t;
ll A[100010];

const int MAX = 100010;
struct edge {
    int to;
    ll cost;
};

vector<edge> G[2][MAX];
ll d[2][MAX];

void dijkstra(int s, int r) {
    priority_queue<P, vector<P>, greater<P> > que;
    for (int i = 0; i < MAX; i++) d[r][i] = inf;
    d[r][s] = 0LL;
    que.push(P(0LL, s));
    while (!que.empty()) {
	P p = que.top(); que.pop();
	int v = p.second;
	if (d[r][v] < p.first) continue;
	for (int i = 0; i < G[r][v].size(); i++) {
	    edge e = G[r][v][i];
	    if (d[r][e.to] > d[r][v] + e.cost) {
		d[r][e.to] = d[r][v] + e.cost;
		que.push(P(d[r][e.to], e.to));
	    }
	}
    }
}

ll solve() {
    dijkstra(0, 0);
    dijkstra(0, 1);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, (t - d[0][i] - d[1][i]) * A[i]);
    }
    return res;
}

void input() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int a, b;
    ll c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        G[0][a].push_back(edge{b, c});
        G[1][b].push_back(edge{a, c});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}