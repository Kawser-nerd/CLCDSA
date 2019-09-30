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
class Cumulative{
    public:
        int h, w;
        vector<vector<T>> c, a;

        Cumulative(const vector<vector<T>>& c, int h, int w)
            : h(h), w(w), c(c), a(h+1, vector<T>(w+1)) {
                for(int i = 1; i <= h; i++){
                    for(int j = 1; j <= w; j++){
                        a[i][j] += c[i-1][j-1] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                    }
                }
            }

        T query(int i, int j, int k, int l){
            return a[k][l] - a[k][j] - a[i][l] + a[i][j];
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    auto s = initVec2<bool>(n, m, false);
    rep(i, n) rep(j, m){
        char c;
        cin >> c;
        if(c == '1'){
            s[i][j] = true;
        }
    }

    auto v = initVec2<int>(n, m);
    auto ev = initVec2<int>(n, m);
    auto eh = initVec2<int>(n, m);
    rep(i, n){
        rep(j, m){
            if(s[i][j]){
                v[i][j] = 1;
            }
            if(i > 0 && s[i-1][j] && s[i][j]){
                ev[i][j] += 1;
            }
            if(j > 0 && s[i][j-1] && s[i][j]){
                eh[i][j] += 1;
            }
        }
    }

    Cumulative<int> vertex(v, n, m);
    Cumulative<int> edgev(ev, n, m);
    Cumulative<int> edgeh(eh, n, m);

    rep(i, q){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << vertex.query(x1 - 1, y1 - 1, x2, y2) - edgev.query(x1, y1 - 1, x2, y2) - edgeh.query(x1 - 1, y1, x2, y2)<< endl;
    }

    return 0;
} ./Main.cpp:25:17: warning: implicit conversion from 'double' to 'int' changes value from 1.0E+15 to 2147483647 [-Wliteral-conversion]
const int INF = 1e15;
          ~~~   ^~~~
1 warning generated.