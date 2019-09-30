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
class segment_tree{
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

        segment_tree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init), init(init), f(f){}

        void update(int i, const T& x){
            i += (n - 1);
            node[i] = x;
            while(i > 0){
                i = (i - 1) / 2;
                node[i] = f(node[2*i+1], node[2*i+2]);
            }
        }

        T query(int s, int t) const {
            return query(s, t, 0, 0, n);
        }
};

signed main(){
    int n, L;
    cin >> n >> L;

    vector<tuple<int, int, int>> t;
    rep(i, n){
        int l, r, c;
        cin >> l >> r >> c;
        t.emplace_back(l, r, c);
    }
    sort(t.begin(), t.end());

    segment_tree<int> dp(L+1, INF, [](int a, int b){return min(a, b);});
    rep(i, n){
        int l = get<0>(t[i]);
        int r = get<1>(t[i]);
        int c = get<2>(t[i]);
        if(l == 0){
            dp.update(r, c);
            continue;
        }
        int tmp = dp.query(l, r+1);
        int rr = dp.query(r, r+1);
        dp.update(r, min(rr, tmp + c));
    }

    cout << dp.query(L, L+1) << endl;

    return 0;
}