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

//Range Sum Query
//segment_tree<int> st(n+1, 0, [](int a, int b){return a+b;});
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

        //[s, t)
        T query(int s, int t) const {
            return query(s, t, 0, 0, n);
        }
};

signed main(){
    int n, k;
    cin >> n >> k;

    vector<int> a;
    rep(i, n){
        a.push_back(i+1);
    }

    segment_tree<int> st(n+1, 0, [](int a, int b){return a+b;});
    rep(i, n){
        st.update(i+1, 1);
    }

    int x = 1;
    int m = n;
    while(x != 0){
        int r = x * m / k;
        x = x * m % k;
        if(x != 0){
            r++;
        }

        int hi = n;
        int lo = 0;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;
            int m = st.query(0, mid+1);
            if(m >= r){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        cout << hi << endl;
        st.update(hi, 0);
        m--;
    }

    for(int i = n; i > 0; i--){
        int b = st.query(i, i+1);
        if(b == 0){
            continue;
        }
        cout << i << endl;
    }

    return 0;
}