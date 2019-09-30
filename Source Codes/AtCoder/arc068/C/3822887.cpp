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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

//Range Sum Query and Range Add Query
template <typename T>
class LazySegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        void eval(int i, int l, int r){
            if(lazy[i] == 0){
                return;
            }

            node[i] += (r - l) * lazy[i];
            if(r - l > 1){
                lazy[i * 2 + 1] += lazy[i];
                lazy[i * 2 + 2] += lazy[i];
            }
            lazy[i] = 0;
        }

        void add(int s, int t, int x, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return;
            }

            if(s <= l && r <= t){
                lazy[i] += x;
                eval(i, l, r);
                return;
            }

            int m = l + (r - l) / 2;
            add(s, t, x, 2 * i + 1, l, m);
            add(s, t, x, 2 * i + 2, m, r);
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }

        T query(int s, int t, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return init;
            }

            if(s <= l && r <= t){
                return node[i];
            }

            int m = l + (r - l) / 2;
            T vl = query(s, t, i * 2 + 1, l, m);
            T vr = query(s, t, i * 2 + 2, m, r);
            return f(vl, vr);
        }

    public:
        int n;
        vector<T> node, lazy;
        T init;
        function<T(T, T)> f;

        LazySegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init) , lazy(calc_size(n) * 2, 0), init(init), f(f) {}

        void update(int i, const T& x){
            node[i + n] = x;
            for(int j = (i + n) / 2; j > 0; j /= 2){
                node[j] = f(node[j * 2 + 1], node[j * 2 + 2]);
            }
        }

        T query(int s, int t){
            return query(s, t, 0, 0, n);
        }

        void add(int s, int t, int x){
            add(s, t, x, 0, 0, n);
        }
};

bool compare(P a, P b){
    return (a.second - a.first) < (b.second - b.first);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<P> range(n);
    rep(i, n){
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(ALL(range), compare);

    int r = 0;
    LazySegmentTree<int> lst(m + 1, 0, [](int a, int b){return a + b;});
    for(int i = 1; i <= m; i++){
        while(r < n && range[r].second - range[r].first + 1 < i){
            lst.add(range[r].first, range[r].second + 1, 1);
            r++;
        }

        int ans = n - r;
        for(int j = i; j <= m; j += i){
            ans += lst.query(j, j+1);
        }
        cout << ans << endl;
    }

    return 0;
}