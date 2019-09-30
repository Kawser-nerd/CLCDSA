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
    int N, D, K;
    vector<int> L, R;

    void input() {
        cin >> N >> D >> K;
        L.resize(D);
        R.resize(D);
        rep(i, 0, D) {
            cin >> L[i] >> R[i];
        }
    }

    int query(int from, int to) {
        int t = 0;
        int l = -1;
        int r = -1;
        for (; t < N; ++t) {
            if (L[t] <= from && from <= R[t]) {
                l = L[t];
                r = R[t];
                break;
            }
        }

        for (; t < N;) {
            if (l <= to && to <= r) {
                return t + 1;
            }
            t++;
            if (max(r, R[t]) - min(l, L[t]) <= R[t] - L[t] + r - l) {
                chmin(l, L[t]);
                chmax(r, R[t]);
            }
        }
        return -1;
    }


    void solve() {
        input();
        rep(i, 0, K) {
            int from, to;
            cin >> from >> to;
            int ans = query(from, to);
            cout << ans << endl;
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