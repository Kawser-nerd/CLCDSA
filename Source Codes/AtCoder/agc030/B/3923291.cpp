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
class Solve {
public:
    void input() {

    }

    ll calc(vector<ll> X, ll L) {


        //L = 1 => n
        int n = X.size();
        ll val = L - X[0];
        ll ret = val;
        for (int i = 1; i < n; ++i) {
            val += L;
            val -= 2 * X[i];
            if (i % 2) {
                val += 2 * X[i / 2];
            } else {
                val += X[i / 2 - 1];
                val += X[i / 2];
            }

            chmax(ret, val);
        }

        val = X[n - 1];
        int state = 1;   //pt1?pt2?
        int pt1 = n - 1; //????-2
        int pt2 = n - 1; //????-1
        for (int i = n - 2; i >= 0; --i) {
            val += L;
            val += 2 * X[i];
            if (state == 1) {
                state = 2;
                val -= 2 * X[pt1];
                pt1--;
            } else {
                state = 1;
                val -= X[pt2];
                val -= X[pt2 - 1];
                pt2--;
            }

            chmax(ret, val);
        }

        return ret;
    }

    void solve() {
        input();
        ll L;
        int N;
        cin >> L >> N;

        vector<ll> X(N);
        rep(i, 0, N) cin >> X[i];

        ll ans = calc(X, L);
        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}