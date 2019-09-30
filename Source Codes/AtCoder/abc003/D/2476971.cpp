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
#define MOD 1000000007

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

ll r, c;
ll x, y;
ll d, l;
Combination cmb(1000);

ll calc4() {
    ll ret = cmb.nCk(x * y, d) * cmb.nCk(x * y - d, l);
    ret %= MOD;
    return ret;
}

ll calc3() {
    ll ret = 0ll;
    if ((x - 1) * y >= d + l && x >= 1) {
        ret += cmb.nCk((x - 1) * y, d) * cmb.nCk((x - 1) * y - d, l);
        ret %= MOD;
    }
    if (x * (y - 1) >= d + l && y >= 1) {
        ret += cmb.nCk(x * (y - 1), d) * cmb.nCk(x * (y - 1) - d, l);
        ret %= MOD;
    }


    ret *= 2ll;
    ret %= MOD;
    return ret;
}

ll calc2() {
    ll ret = 0ll;
    ll a = x, b = y;
    if ((a - 2) * b >= d + l && a >= 2) {
        ret += cmb.nCk((a - 2) * b, d) * cmb.nCk((a - 2) * b - d, l);
        ret %= MOD;
    }

    swap(a, b);
    if ((a - 2) * b >= d + l && a >= 2) {
        ret += cmb.nCk((a - 2) * b, d) * cmb.nCk((a - 2) * b - d, l);
        ret %= MOD;
    }
    if ((x - 1) * (y - 1) >= d + l && x >= 1 && y >= 1) {
        ret += 4 * cmb.nCk((x - 1) * (y - 1), d) * cmb.nCk((x - 1) * (y - 1) - d, l);
        ret %= MOD;
    }

    return ret;
}

ll calc1() {
    ll ret = 0ll;
    if ((x - 1) * (y - 2) >= d + l && x >= 1 && y >= 2) {
        ret += cmb.nCk((x - 1) * (y - 2), d) * cmb.nCk((x - 1) * (y - 2) - d, l);
        ret %= MOD;
    }

    if ((x - 2) * (y - 1) >= d + l && x >= 2 && y >= 1) {
        ret += cmb.nCk((x - 2) * (y - 1), d) * cmb.nCk((x - 2) * (y - 1) - d, l);
        ret %= MOD;
    }

    ret *= 2ll;
    ret %= MOD;
    return ret;
}

ll calc0() {
    ll ret = 0ll;
    if ((x - 2) * (y - 2) >= d + l && x >= 2 && y >= 2) {
        ret += cmb.nCk((x - 2) * (y - 2), d) * cmb.nCk((x - 2) * (y - 2) - d, l);
        ret %= MOD;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    cin >> x >> y;
    cin >> d >> l;

    if (d + l == 0) {
        cout << 1 << endl;
        return 0;
    }
    ll ans = 0ll;
    ans += calc4();
    ans %= MOD;

    ans -= calc3();
    ans %= MOD;
//
    ans += calc2();
    ans %= MOD;
//
    ans -= calc1();
    ans %= MOD;
//
    ans += calc0();
    ans %= MOD;

    ans *= (r - x + 1);
    ans %= MOD;
    ans *= (c - y + 1);
    ans %= MOD;

    if (ans < 0) ans += MOD;

    cout << ans << endl;

    return 0;
}