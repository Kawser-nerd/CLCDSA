#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
template <class T> bool setmax(T & l, T const & r) { if (not (l < r)) return false; l = r; return true; }
using namespace std;
int slove_a(vector<vector<int> > const & a, vector<bool> const & forbidden) {
    int n = a.size();
    vector<vector<int> > a_inv(n); repeat (i,n) for (int j : a[i]) a_inv[j].push_back(i);
    vector<int> indeg(n);
    queue<int> q; repeat (i,n) if (not forbidden[i] and a[i].empty()) q.push(i);
    int cnt = 0;
    while (not q.empty()) {
        int i = q.front(); q.pop();
        ++ cnt;
        for (int j : a_inv[i]) if (not forbidden[j]) {
            ++ indeg[j];
            if (indeg[j] == a[j].size()) {
                q.push(j);
            }
        }
    }
    return cnt;
}
int main() {
    int n, al; cin >> n >> al;
    vector<vector<int> > a(n); // x to y
    repeat (i,al) {
        int x, y; cin >> x >> y; -- x; -- y;
        a[x].push_back(y);
    }
    int bl; cin >> bl;
    vector<vector<int> > b(n); // u to v
    vector<int> u(bl);
    repeat (i,bl) {
        int v; cin >> u[i] >> v; -- u[i]; -- v;
        b[u[i]].push_back(v);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    int ul = u.size();
    int ans = 0;
    repeat (s,1<<ul) {
        // remove restriction b
        vector<vector<int> > c = a;
        vector<bool> forbidden(n);
        repeat (i,ul) {
            if (s&(1<<i)) {
                for (int v : b[u[i]]) {
                    c[v].push_back(u[i]);
                }
            } else {
                forbidden[u[i]] = true;
            }
        }
        setmax(ans, slove_a(c, forbidden));
    }
    cout << ans << endl;
    return 0;
}