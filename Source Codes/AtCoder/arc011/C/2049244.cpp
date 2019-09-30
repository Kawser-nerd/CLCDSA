#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
#define int ll

const int MOD = 1e9 + 7;
const int INF = 1e15 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int diff(const string& a, const string& b) {
    int ans = 0;
    int n = a.size();
    rep(i, n) {
        if (a[i] != b[i]) {
            ans++;
        }
    }
    return ans;
}

pair<vector<int>, vector<int>> dijkstra(int n, const vector2<int>& g, int s) {
    vector<int> p(n, -1);
    p[s] = s;

    vector<int> d(n, INF);
    d[s] = 0;

    typedef pair<double, int> P;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0, s));

    while (not q.empty()) {
        int c = q.top().first;
        int v = q.top().second;
        q.pop();

        if (c > d[v]) {
            continue;
        }

        rep(u, n) {
            int alt_c = c + g[v][u];
            if (alt_c < d[u]) {
                d[u] = alt_c;
                p[u] = v;
                q.push(make_pair(alt_c, u));
            }
        }
    }

    return make_pair(d, p);
}

template <typename T>
void dump(const vector<T>& v) {
    cout << "[";
    for (T e : v) {
        cout << e << ", ";
    }
    cout << "]" << endl;
}

signed main() {
    string a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    vector<string> s;
    s.push_back(a);
    s.push_back(b);
    rep(i, n) {
        string x;
        cin >> x;
        s.push_back(x);
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    int m = s.size();
    vector2<int> g = init_vector2(m, m, INF);

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (diff(s[i], s[j]) == 1) {
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }

    int ai = find(s.begin(), s.end(), a) - s.begin();
    int bi = find(s.begin(), s.end(), b) - s.begin();

    auto dijk = dijkstra(m, g, ai);
    vector<int> dis = dijk.first;
    vector<int> par = dijk.second;

    if (dis[bi] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    for (int i = par[bi]; i != ai; i = par[i]) {
        ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    cout << a << endl;
    for (int i : ans) {
        cout << s[i] << endl;
    }
    cout << b << endl;

    return 0;
}