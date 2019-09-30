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
ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return gcd(b, a % b);

}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

class Solve {
public:
    void input() {

    }

    void solve() {
        input();
        ll a, b, n;
        cin >> a >> b >> n;
        ll lab = lcm(a, b);
        if (lab >= n) {
            cout << lab << endl;
        } else {
            if (n % lab == 0) {
                cout << n << endl;
            } else {
                ll ans = (n / lab + 1) * lab;
                cout << ans << endl;
            }
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}