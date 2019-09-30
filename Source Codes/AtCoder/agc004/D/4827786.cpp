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
    int N, K;
    vector<int> A;
    vector<vector<int>> treeone;

    void input() {
        cin >> N >> K;
        A.resize(N);
        treeone.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            A[i]--;
            if (i == 0) {
                continue;
            } else {
                treeone[A[i]].push_back(i);
            }
        }
    }

    vector<int> memo;

    int dfs(int v, int d) {
//        if (treeone[v].size() == 0) {
//            return memo[v] = d > K;
//        }

        int val = 0;
        for (auto e : treeone[v]) {
            int tmp = dfs(e, d + 1);
            if (tmp < K) {
                chmax(val, tmp);
            }
        }
        if (val == 0) {
            return memo[v] = d > K;
        }
        return memo[v] = val + 1;
    }

    void solve() {
        input();
        if (K == 1) {
            int ans = 0;
            for (auto e : A) {
                ans += e != 0;
            }
            cout << ans << endl;
            return;
        }

        int ans = A[0] != 0;
        memo.resize(N);
        dfs(0, 0);
        for (int i = 1; i < N; ++i) {
            if (memo[i] == K) ans++;
        }

        cout << ans << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}