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

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e10;
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
    int n;
    cin >> n;

    vector<int> b(n+1), w(n+1);
    rep(i, n * 2){
        char c;
        int a;
        cin >> c >> a;
        if(c == 'W'){
            w[a] = i;
            continue;
        }
        b[a] = i;
    }

    vector<vector<int>> costb(n+1, vector<int>(n+1));
    vector<vector<int>> costw(n+1, vector<int>(n+1));

    segment_tree<int> bst(2*n+1, 0, [](int a, int b){return a+b;});
    for(int i = n; i > 0; i--){
        bst.update(b[i], 1);

        int ww = 0;
        for(int j = n; j >= 0; j--){
            costb[i-1][j] = ww + bst.query(0, b[i]);
            if(w[j] < b[i]){
                ww++;
            }
        }
    }

    segment_tree<int> wst(2*n+1, 0, [](int a, int b){return a+b;});
    for(int j = n; j > 0; j--){
        wst.update(w[j], 1);

        int bb = 0;
        for(int i = n; i >= 0; i--){
            costw[i][j-1] = bb + wst.query(0, w[j]);
            if(b[i] < w[j]){
                bb++;
            }
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
    dp[0][0] = 0;
    rep(i, n+1){
        rep(j, n+1){
            if(i < n){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + costb[i][j]);
            }
            if(j < n){
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + costw[i][j]);
            }
        }
    }

    cout << dp[n][n] << endl;

    return 0;
} ./Main.cpp:22:17: warning: implicit conversion from 'double' to 'int' changes value from 1.0E+10 to 2147483647 [-Wliteral-conversion]
const int INF = 1e10;
          ~~~   ^~~~
1 warning generated.