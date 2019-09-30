#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using namespace std;
template <class T> void setmax(T & a, T const & b) { if (a < b) a = b; }
const int inf = 1e9+7;
int main() {
    int n; cin >> n;
    vector<vector<int> > g(n);
    repeat (i, n-1) {
        int a, b; cin >> a >> b; -- a; -- b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k; cin >> k;
    vector<int> l(n, - inf), r(n, inf); // [l, r)
    repeat (i, k) {
        int v, p; cin >> v >> p; -- v;
        l[v] = p;
        r[v] = p+1;
    }
    const int root = 0;
    function<bool (int, int)> go1 = [&](int i, int parent) {
        vector<int> ls, rs;
        ls.push_back(l[i]);
        rs.push_back(r[i]);
        for (int j : g[i]) if (j != parent) {
            if (not go1(j, i)) return false;
            ls.push_back(max(- inf, l[j] - 1));
            rs.push_back(min(  inf, r[j] + 1));
        }
        l[i] = *whole(max_element, ls); for (int lj : ls) if (lj != - inf and lj % 2 != l[i] % 2) return false;
        r[i] = *whole(min_element, rs); for (int rj : rs) if (rj !=   inf and rj % 2 != r[i] % 2) return false;
        if (r[i] - l[i] <= 0) return false;
        return true;
    };
    bool possible = go1(root, -1);
    cout << (possible ? "Yes" : "No") << endl;
    if (possible) {
        vector<int> result(n, - inf);
        function<void (int, int)> go2 = [&](int i, int parent) {
            result[i] = l[i];
            for (int j : g[i]) if (j != parent) {
                setmax(l[j], l[i] - 1);
                go2(j, i);
            }
        };
        go2(root, -1);
        for (int it : result) cout << it << endl;
    }
    return 0;
}