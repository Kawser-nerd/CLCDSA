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
    int N;
    vector<int> C;
    vector<vector<int>> D;
    vector<int> prev;
    int max_C = 200001;

    void input() {
        cin >> N;
        C.resize(N);
        D.resize(max_C);
        rep(i, 0, N) {
            cin >> C[i];
            C[i]--;
            D[C[i]].push_back(i);
        }
        prev.resize(N, -1);
        for (int i = 0; i < max_C; ++i) {
            for (int j = 1; j < D[i].size(); ++j) {
                prev[D[i][j]] = D[i][j - 1];
            }
        }
    }

    void solve() {
        input();
        vector<ll> dp(N);
        dp[0] = 1;
        for (int i = 1; i < N; ++i) {
            if (prev[i] != -1 && prev[i] != i - 1) {
                dp[i] = (dp[i - 1] + dp[prev[i]]) % MOD;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        cout << dp[N - 1] << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}