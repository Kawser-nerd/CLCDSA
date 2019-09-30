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

//Mat[0] : ?0?????
typedef vector<int> Vec;
typedef vector<Vec> Mat;

//??B : A(B) -> C
Vec trans(Vec a, Vec b){
    Vec c(b.size());
    for(int i = 0; i < (int)a.size(); i++){
        c[i] = b[a[i]];
    }
    return c;
}

Vec powTrans(Vec a, int n){
    Vec b(a.size());;
    for(int i = 0; i < (int)a.size(); i++){
        b[i] = i;
    }

    while(n != 0){
        if(n % 2 == 1){
            b = trans(a, b);
        }

        n /= 2;
        a = trans(a, a);
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int m, k;
    cin >> m >> k;
    vector<int> a(m);
    rep(i, m){
        cin >> a[i];
        a[i]--;
    }

    vector<int> y(n - 1);
    rep(i, n - 1){
        y[i] = x[i+1] - x[i];
    }

    vector<int> z(n - 1);
    rep(i, n - 1) z[i] = i;
    rep(i, m){
        swap(z[a[i]-1], z[a[i]]);
    }

    Vec yy = trans(powTrans(z, k), y);
    vector<int> ans(n);
    ans[0] = x[0];
    rep(i, n - 1){
        ans[i+1] = ans[i] + yy[i];
    }

    rep(i, n){
        cout << ans[i] << endl;
    }

    return 0;
}