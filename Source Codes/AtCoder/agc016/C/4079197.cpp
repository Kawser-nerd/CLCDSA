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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, x, y;
    cin >> h >> w >> x >> y;

    if(h % x == 0 && w % y == 0){
        cout << "No" << endl;
        return 0;
    }

    int plus = ((h + x - 1) / x) * ((w + y - 1) / y);
    int minus = (h / x) * (w / y);
    int ans = 1;
    while(ans * plus <= (ans + 1) * minus){
        ans++;
    }

    cout << "Yes" << endl;
    rep(i, h){
        rep(j, w){
            if(i % x == 0 && j % y == 0){
                cout << ans << " ";
            }else if((i + 1) % x == 0 && (j + 1) % y == 0){
                cout << - ans - 1 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}