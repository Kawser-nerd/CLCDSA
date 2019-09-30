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

    pair<double, double> mz(double w1, double p1, double w2, double p2) {
        double retw = w1 + w2;
        double tmp = w1 * p1 + w2 * p2;
        double retp = tmp / retw;
        return make_pair(retw, retp);
    }

    void solve() {
        input();
        int N, K;
        cin >> N >> K;
        vector<double> w(N), p(N);
        vector<bool> used(N, false);

        rep(i, 0, N) {
            cin >> w[i] >> p[i];
            p[i] /= 100.0;
        }

        double W = 0.0, P = 0.0;
        for (int _ = 0; _ < K; ++_) {
            double tmpW = W, tmpP = P;
            int key = -1;
            for (int i = 0; i < N; ++i) {
                if (!used[i]) {
                    auto tmp = mz(W, P, w[i], p[i]);
                    if (key == -1 || tmp.second > tmpP) {
                        tmpW = tmp.first;
                        tmpP = tmp.second;
                        key = i;
                    }
                }
            }
            W = tmpW;
            P = tmpP;
            used[key] = true;
        }

        cout << fixed << setprecision(9);
        cout << P * 100 << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}