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
    int N, K;
    vector<double> w, p;

    void input() {
        cin >> N >> K;
        w.resize(N);
        p.resize(N);
        rep(i, 0, N) {
            cin >> w[i] >> p[i];
            p[i] /= 100;
        }
    }

    bool check(double x) {
        vector<double> g;
        for (int i = 0; i < N; ++i) {
            double tmp = w[i] * (p[i] - x);
            g.push_back(tmp);
        }
        sort(all(g));
        reverse(all(g));
        double sum = 0.0;
        for (int i = 0; i < K; ++i) {
            sum += g[i];
        }
        return sum >= 0.0;
    }

    void solve() {
        input();
        double lb = 0.0, ub = 1.0;
        rep(_, 0, 100) {
            double mid = (ub + lb) / 2;
            if (check(mid)) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        cout << fixed << setprecision(9);
        cout << lb * 100 << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}