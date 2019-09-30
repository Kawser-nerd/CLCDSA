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
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
class pertially_persistent_union_find{
    private:
        int n;
        vector<T> rank, time;
        vector<vector<P>> add;
        int now;

    public:
        pertially_persistent_union_find(int n)
            : n(n), rank(n+1, 1), time(n+1, INF), add(n+1), now(0) {
                rep(i, n+1){
                    add[i].emplace_back(0, 1);
                }
            }

        int find(int v, int t){
            if(time[v] > t){
                return v;
            }

            return find(rank[v], t);
        }

        bool unite(int u, int v){
            ++now;
            int u_root = find(u, now);
            int v_root = find(v, now);

            if(u_root == v_root){
                return false;
            }

            if(rank[u_root] < rank[v_root]){
                swap(u_root, v_root);
            }

            //?: u, ?: v
            rank[u_root] += rank[v_root];
            rank[v_root] = u_root;
            add[u_root].emplace_back(now, rank[u_root]);
            time[v_root] = now;
            return true;
        }

        int size(int v, int t){
            int v_root = find(v, t);

            int lo = 0;
            int hi = add[v_root].size();
            while(hi - lo > 1){
                int mid = (hi + lo) / 2;
                if(add[v_root][mid].first <= t){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            return add[v_root][lo].second;
        }

        //(u, v)?????????
        //??????-1
        int unioned_time(int u, int v){
            int lo = -1;
            int hi = now + 1;
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                int pu = find(u, mid);
                int pv = find(v, mid);

                if(pu == pv){
                    hi = mid;
                }else{
                    lo = mid;
                }
            }
            return hi != now + 1 ? hi : -1;
        }

        int getTime(){
            return now;
        }
};

signed main(){
    int n, m;
    cin >> n >> m;

    pertially_persistent_union_find<int> uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    int q;
    cin >> q;

    rep(i, q){
        int x, y, z;
        cin >> x >> y >> z;

        int lo = -1;
        int hi = m;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            int px = uf.find(x, mid);
            int py = uf.find(y, mid);

            if((px == py && uf.size(px, mid) >= z) || (px != py && uf.size(px, mid) + uf.size(py, mid) >= z)){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        cout << hi << endl;
    }

    return 0;
}