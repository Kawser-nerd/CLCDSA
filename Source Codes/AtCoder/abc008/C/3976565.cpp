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
    int N;
    vector<int> C;


    void input() {
        cin >> N;
        C.resize(N);
        rep(i, 0, N) cin >> C[i];

    }

    double calc(int c) {
        double ret = 0.0;
        int k = 0;
        vector<int> D;
        for (int i = 0; i < N; ++i) {
            if (i != c) D.push_back(C[i]);

            if (i != c && C[c] % C[i] == 0) {
                k++;
            }
        }

        vector<vector<double> > dp(N, vector<double>(N, 0.0));
        dp[0][0] = 1.0;

        for (int i = 0; i < N - 1; ++i) {
            for (int j = 0; j < N - 1; ++j) {
                int nokori = N - 1 - i;

                //?????????
                dp[i + 1][j] += dp[i][j] * (N - 1 - k - (i - j)) / (nokori);

                //???????
                dp[i + 1][j + 1] += dp[i][j] * (k - j) / (nokori);
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; j += 2) {
                ret += dp[i][j];
            }
        }

        ret /= N;

        return ret;
    }

    void solve() {
        input();

        double ans = 0.0;
        for (int i = 0; i < N; ++i) {
            double tmp = 0.0;
            tmp = calc(i);
            ans += tmp;
        }

        cout << fixed << setprecision(9);
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}