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

int N, M;
vector<vector<int> > G;

vector<int> color;

// ?????0
// ???????1
// ???????????-1
// paint(v,1)?????
int paint(int v, int c) {
    if (G[v].size() == 0) return 0;
    if (color[v] != 0) {
        if (color[v] != c) return -1;
        return 1;
    }

    color[v] = c;
    int ret = 1;

    for (auto e : G[v]) {
        if (paint(e, -c) == -1) {
//            return -1;
            ret = -1;
        }
    }

    return ret;


}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    G.resize(N);
    color.resize(N);


    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // x ?????? y ?? z ???
    //(x + y) ^ 2 + y * y + 2 * z * N - 1???
    ll x = 0ll, y = 0ll, z = 0ll;

    for (int i = 0; i < N; ++i) {
        if (color[i] == 0) {
            int val = paint(i, 1);
            if (val == 0) z++;
            if (val == 1) y++;
            if (val == -1) x++;
        }
    }

//    ll ans = (x + y) * (x + y) + y * y + 2 * z * N - 1;
    ll ans = 1ll * N * N - 1ll * (N - z) * (N - z) + (x + y) * (x + y) + y * y;
    cout << ans << endl;

    return 0;
}