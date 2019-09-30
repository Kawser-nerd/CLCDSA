#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????


int X1, Y1, X2, Y2;

bool check(int x, int y) {
    return x >= min(X1, X2) && x <= max(X1, X2) && y >= min(Y1, Y2) && y <= max(Y1, Y2);
}


int compute_LIS(vector<int> v) {
    vector<int> dp(v.size() + 1, INF);

    for (auto e : v) {
        int key = lower_bound(all(dp), e) - dp.begin();
        dp[key] = e;
    }

//    int ret = lower_bound(all(dp),INF) - dp.begin() - 1;
    int ret = lower_bound(all(dp), INF) - dp.begin();
    return ret;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    X1 = x1, Y1 = y1, X2 = x2, Y2 = y2;

    int N;
    cin >> N;

    // x1 < x2, y1 < y2?????????
    // x1 == x2 or y1 == y2 ??????????
    // x1 > x2???????, y1 > y2??value???


    using P = pair<int, int>;
    vector<P> vp;

    rep(i, 0, N) {
        P p;
        cin >> p.first >> p.second;
        if (check(p.first, p.second)) {
            vp.push_back(p);
        }
    }

    sort(all(vp));
    vector<int> v;
    for (auto e : vp) {
        v.push_back(e.second);
    }


    const double pi = 3.14159265358979323846;
//    if (x1 == x2 || y1 == y2) {
//        //hoge???
//        double ans = 100.0 * (abs(x1 - x2) + abs(y1 - y2));
//        if (v.size()) {
//            ans += 10.0 * pi - 20;
//        }
//        cout << ans << endl;
//        return 0;
//    }

    if (1ll * (x2 - x1) * (y2 - y1) < 0) {
        //reverse??
        reverse(all(v));
    }

//    if (y1 > y2) {
//        //????
//        for (int i = 0; i < v.size(); ++i) {
//            v[i] *= -1;
//        }
//    }

    //v????????????
    int len = compute_LIS(v);
    double ans;
    if (len == v.size() && v.size() > 0) {
        if ((abs(y1 - y2) + 1) == len || (abs(x1 - x2) + 1) == len) {
            ans = 100.0 * (abs(x1 - x2) + abs(y1 - y2)) + (len - 1) * (-20.0 + 5 * pi) + (10.0 * pi - 20);
        }else{
//            ans = 100.0 * (abs(x1 - x2) + abs(y1 - y2)) + (len - 1) * (-20.0 + 5 * pi) + (10.0 * pi - 20);
            ans = 100.0 * (abs(x1 - x2) + abs(y1 - y2)) + len * (-20.0 + 5 * pi);
        }
    } else {
        ans = 100.0 * (abs(x1 - x2) + abs(y1 - y2)) + len * (-20.0 + 5 * pi);
    }
    cout << ans << endl;


    return 0;
}