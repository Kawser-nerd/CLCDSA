#include <iostream>
#include <vector>
#include <functional>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
using namespace std;
template <class T> void setmax(T & a, T const & b) { if (a < b) a = b; }
int main() {
    // input
    int n, k; cin >> n >> k;
    vector<vector<int> > g(n);
    repeat (i,n-1) {
        int a, b; cin >> a >> b;
        -- a; -- b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // compute
    function<int (int, int, int)> dfs = [&](int i, int p, int depth) {
        int cnt = 1;
        if (depth) for (int j : g[i]) if (j != p) {
            cnt += dfs(j, i, depth-1);
        }
        return cnt;
    };
    int cnt = 0;
    if (k % 2 == 0) {
        repeat (i,n) {
            setmax(cnt, dfs(i, -1, k/2));
        }
    } else {
        repeat (i,n) {
            for (int j : g[i]) {
                setmax(cnt, dfs(i, j, k/2) + dfs(j, i, k/2));
            }
        }
    }
    // output
    cout << n - cnt << endl;
    return 0;
}