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

template <typename T>
class SegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        T query(int s, int t, int i, int l, int r) const {
            if(r <= s || t <= l){
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
        vector<T> node;
        T init;
        function<T(T, T)> f;

        SegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init), init(init), f(f){}

        void update(int i, const T& x){
            i += (n - 1);
            node[i] = x;
            while(i > 0){
                i = (i - 1) / 2;
                node[i] = f(node[2*i+1], node[2*i+2]);
            }
        }

        //[s, t)
        T query(int s, int t) const {
            return query(s, t, 0, 0, n);
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> c(n), a(n);
    for(int i = 1; i < n; i++){
        cin >> c[i] >> a[i];
    }

    //Range Minimum Query
    SegmentTree<int> st(n+1, INF, [](int a, int b){return min(a, b);});
    rep(i, n){
        st.update(i, -1);
    }
    vector<int> g(n);
    g[0] = 0;
    st.update(0, 0);

    for(int i = 1; i < n; i++){
        int lo = 0;
        int hi = n;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;
            if(st.query(0, mid) >= i - c[i]){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        g[i] = lo;
        st.update(lo, i);
    }

    int ans = 0;
    rep(i, n){
        if(a[i] % 2){
            ans ^= g[i];
        }
    }

    if(ans == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
    return 0;
}