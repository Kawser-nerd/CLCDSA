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

        //[s, t)
        T query(int s, int t) const {
            return query(s, t, 0, 0, n);
        }
};

signed main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        a[i] -= k;
    }

    vector<int> s(n+1);
    rep(i, n){
        s[i+1] = s[i] + a[i];
    }

    vector<int> t = s;
    sort(t.begin(), t.end());
    map<int, int> encode;
    vector<int> decode;
    int m = 0;
    rep(i, n+1){
        if(encode.find(t[i]) == encode.end()){
            encode.emplace(t[i], m++);
            decode.push_back(t[i]);
        }
    }

    int ans = 0;
    //Range Sum Query
    segment_tree<int> st(m+1, 0, [](int a, int b){return a+b;});
    for(int i = n; i >= 0; i--){
        int x = encode[s[i]];
        int cnt = st.query(x, x+1);
        ans += st.query(x, m);
        st.update(x, cnt+1);
    }
    cout << ans << endl;

    return 0;
}