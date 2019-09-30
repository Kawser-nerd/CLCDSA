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
    vector<vector<int> > G;
    vector<int> memo;

    void input() {
        cin >> N;
        G.resize(N);
        memo.resize(N);

        for (int i = 1; i < N; ++i) {
            int tmp;
            cin >> tmp;
            tmp--;
            G[tmp].push_back(i);
        }
    }

    int dfs(int v) {
        int min_v = INF;
        int max_v = -1;
        if (G[v].size() == 0) return 1;
        for (auto nv : G[v]) {
            int tmp = dfs(nv);
            chmin(min_v, tmp);
            chmax(max_v, tmp);
        }
        return min_v + max_v + 1;
    }

    void solve() {
        input();
        int ans = dfs(0);
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