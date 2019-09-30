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
#include <cstring>

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
    int N, A, B;
    using P = pair<int, int>;

    void input() {
        cin >> N >> A >> B;
    }

    int bitcount(int n) {
        int ret = 0;
        for (int i = 0; n >> i > 0; ++i) {
            if (n >> i & 1) ret++;
        }
        return ret;
    }

    vector<P> rec(P x, P y) {
        if (bitcount(x.second) == 1) {
            vector<P> ret = {x, y};
            return ret;
        }
        int k = -1;
        for (int i = 0; i < N; ++i) {
            if (x.second >> i & 1 && y.second >> i & 1 && (x.first >> i & 1) != (y.first >> i & 1)) {
                k = i;
                break;
            }
        }
        if (k == -1)
            exit(-1);

        P xd = x;
        xd.second -= 1 << k;
        P yd = y;
        yd.second -= 1 << k;
        P c = xd;
//        c.first ^= 1;
        for (int i = 0; i < N; ++i) {
            if (c.second >> i & 1) {
                c.first ^= 1 << i;
                break;
            }
        }

        auto pre = rec(xd, c);
        for (auto &e : pre) {
            if (x.first >> k & 1) {
                e.first |= 1 << k;
            } else {
                e.first = ~e.first;
                e.first |= 1 << k;
                e.first = ~e.first;
            }
            e.second |= 1 << k;
        }
        auto suf = rec(c, yd);
        for (auto &e : suf) {
            if (y.first >> k & 1) {
                e.first |= 1 << k;
            } else {
                e.first = ~e.first;
                e.first |= 1 << k;
                e.first = ~e.first;
            }
            e.second |= 1 << k;
        }

        vector<P> ret(all(pre));
//        ret.push_back(suf);
        for (auto e : suf) ret.push_back(e);

        return ret;
    }


    void solve() {
        input();
        if (bitcount(A ^ B) % 2 == 0) {
            cout << "NO" << endl;
            return;
        }

        P a = P(A, (1 << N) - 1);
        P b = P(B, (1 << N) - 1);
        auto ans = rec(a, b);
        cout << "YES" << endl;
        for (auto e : ans) {
            cout << e.first << " ";
        }
        cout << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}