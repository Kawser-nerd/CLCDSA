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
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

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

    string ss;
    cin >> ss;
    int n = SZ(ss);
    vector<int> s(n);
    rep(i, n) s[i] = ss[i] - 'a';

    vector<int> c(26);
    rep(i, n){
        c[s[i]]++;
    }
    int odd = 0;
    int oddidx = -1;
    rep(i, 26){
        if(c[i] % 2){
            odd++;
            oddidx = i;
        }
    }

    if(odd > 1){
        cout << -1 << endl;
        return 0;
    }

    vector<deque<int>> vd(26, deque<int>());
    rep(i, n){
        vd[s[i]].push_back(i);
    }
    vector<int> cc(26);
    vector<int> t(n);

    int id = 0;
    rep(i, n / 2){
        while(cc[s[id]] >= c[s[id]] / 2){
            id++;
        }
        t[i] = id;
        t[n-1-i] = vd[s[id]].back();
        vd[s[id]].pop_front();
        vd[s[id]].pop_back();
        cc[s[id]]++;
        id++;
    }

    if(n % 2){
        rep(i, 26){
            if(SZ(vd[i]) > 0){
                t[n/2] = vd[i].front();
                break;
            }
        }
    }

    int ans = 0;
    SegmentTree<int> st(n+1, 0, [](int a, int b){return a+b;});
    rep(i, n){
        ans += st.query(t[i], n);
        st.update(t[i], 1);
    }
    cout << ans << endl;

    return 0;
}