#include <iostream>
#include <vector>
#include <queue>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;
int main() {
    // input
    int n, m; cin >> n >> m;
    vector<vector<int> > g(n);
    repeat (i,m) {
        int u, v; cin >> u >> v; -- u; -- v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // decompose
    int a_components = 0, a_nodes = 0; // connected graph: |V|  = 1
    int b_components = 0, b_nodes = 0; // connected graph: |V| >= 2 and no odd cyles
    int c_components = 0, c_nodes = 0; // connected graph: |V| >= 2 and odd cycles exist
    vector<char> used(n);
    repeat (root,n) if (not used[root]) {
        bool is_bipartite = true;
        int size = 0;
        queue<int> que;
        que.push(root);
        used[root] = 'A';
        while (not que.empty()) {
            int i = que.front(); que.pop();
            ++ size;
            for (int j : g[i]) {
                if (used[j]) {
                    if (used[i] == used[j]) is_bipartite = false;
                } else {
                    used[j] = (used[i] == 'A' ? 'B' : 'A');
                    que.push(j);
                }
            }
        }
        if (size == 1) {
            ++ a_components; a_nodes += size;
        } else if (is_bipartite) {
            ++ b_components; b_nodes += size;
        } else {
            ++ c_components; c_nodes += size;
        }
    }
    // output
    ll ans = 0;
    ans += a_nodes *(ll) a_nodes; // A A
    ans += 2 * a_nodes *(ll) b_nodes; // A B ; B A
    ans += 2 * a_nodes *(ll) c_nodes; // A C ; C A
    ans += b_components *(ll) b_components * 2; // B B
    ans += 2 * b_components *(ll) c_components; // B C ; C B
    ans += c_components *(ll) c_components; // C C
    cout << ans << endl;
    return 0;
}