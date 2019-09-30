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
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 998244353

//????????
class Combination {

public:
    vector<ll> fact;

    Combination(int max_n) {
        //1 ~ n!?????mod????
        int n = max_n;
        vector<ll> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        this->fact = fact;
    }

    template<typename T>
    //template????????
    ll pow(T x, int y) {
        if (y == 0) return 1;
        if (y == 1) return x;
        if (y == 2) return (x * x) % MOD;
//        if (y % 2 == 1) return pow(x, y / 2) * pow(x, y / 2) % MOD;
        if (y % 2 == 1) return pow(pow(x, y / 2), 2) * x % MOD;
//        return pow(x, y / 2) * pow(x, y / 2) % MOD;
        return pow(pow(x, y / 2), 2) % MOD;
    }

    ll nCk(int n, int k) {
//        return (fact[n] * pow(fact[n-k],MOD-2) * pow(fact[k],MOD-2)) % MOD;
        return (((fact[n] * pow(fact[n - k], MOD - 2)) % MOD) * pow(fact[k], MOD - 2)) % MOD;
    }
};

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return gcd(b, a % b);

}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    Combination comb(300);
    vector<int> x(N), y(N);
    rep(i, 0, N) {
        cin >> x[i] >> y[i];
    }
//    map<pair<int, int>, int> mp;
    ll ans = comb.pow(2, N) - 1 - N;
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];

            int adx = abs(dx);
            int ady = abs(dy);
            int div;
            if (dx == 0 && dy == 0) continue;
            if (dy == 0) {
                dx = 1;
            } else if (dx == 0) {
                dy = 1;
            } else {
                div = gcd(adx, ady);
                dx /= div;
                dy /= div;
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
            }
            int cnt = 2;
            bool flag = true;
            rep(k, 0, N) {
                int dx2 = x[k] - x[i];
                int dy2 = y[k] - y[i];

//                    if (dx2 == 0 && dy2 == 0) continue;
//                    if (dy2 == 0) {
//                        dx2 = 1;
//                    } else if (dx2 == 0) {
//                        dy2 = 1;
//                    } else {
//                        div = gcd(abs(dx2), abs(dy2));
//                        dx2 /= div;
//                        dy2 /= div;
//                    }
//                    if (dx * dy2 == dx2 * dy) {
//                        mp[pair<int, int>(dx, dy)]++;
//                    }
//                if (dx2 == 0 && dy2 == 0) continue;
//                if (dx2 == dx && dy2 == dy) continue;
                if(i == k || j == k) continue;
                if (dx == 0) {
                    if (dx2 == 0) {
//                        mp[pair<int, int>(dx, dy)]++;
                        cnt++;
                        if (k < j) {
                            flag = false;
                        }
                    }
                } else if (dy == 0) {
                    if (dy2 == 0) {
//                        mp[pair<int, int>(dx, dy)]++;
                        cnt++;
                        if (k < j) {
                            flag = false;
                        }
                    }
                } else {
                    if (dx * dy2 == dx2 * dy) {
//                        mp[pair<int, int>(dx, dy)]++;
                        cnt++;
                        if (k < j) {
                            flag = false;
                        }
                    }
                }
            }
            if(flag){
                ll minus = comb.pow(2, cnt) - 1 - cnt;
                ans -= minus;
//                cout << x[i] << " " <<  y[i] << " " << minus << endl;
                if(ans < 0) ans += MOD;
            }

//            if (mp.find(pair<int, int>(dx, dy)) == mp.end()) {
//                mp[pair<int, int>(dx, dy)] = 2;
//
//            }

        }
    }
    if (ans < 0) ans += MOD;
//    for (auto e : mp) {
//        int k = e.second;
//        cout << e.first.first << " " << e.first.second << " " << k << endl;
//        ll minus = comb.pow(2, k) - 1 - k;
//        ans -= minus;
//        cout << minus << endl;
//        if (ans < 0) ans += MOD;
//    }
    cout << ans << endl;


    return 0;
}