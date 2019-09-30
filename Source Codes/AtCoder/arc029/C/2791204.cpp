#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
class union_find{
    public:
        int n;
        vector<T> p, rank;

        union_find(int n)
            : n(n), p(n+1, -1), rank(n+1) {}

        int find(int v){
            if(p[v] == -1){
                return v;
            }
            p[v] = find(p[v]);
            return p[v];
        }

        void unite(int u, int v){
            int u_root = find(u);
            int v_root = find(v);

            if(u_root == v_root){
                return;
            }

            if(rank[u_root] < rank[v_root]){
                swap(u_root, v_root);
            }

            if(rank[u_root] == rank[v_root]){
                rank[u]++;
            }

            p[v_root] = u_root;
        }
};

signed main(){
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edge;
    rep(i, n){
        int c;
        cin >> c;
        edge.emplace_back(c, 0, i+1);
    }
    rep(i, m){
        int a, b, r;
        cin >> a >> b >> r;
        edge.emplace_back(r, a, b);
    }
    sort(edge.begin(), edge.end());

    union_find<int> uf(n);
    int ans = 0;
    rep(i, n+m){
        int w = get<0>(edge[i]);
        int u = get<1>(edge[i]);
        int v = get<2>(edge[i]);

        int u_r = uf.find(u);
        int v_r = uf.find(v);
        if(u_r == v_r){
            continue;
        }
        uf.unite(u, v);
        ans += w;
    }
    cout << ans << endl;

    return 0;
}