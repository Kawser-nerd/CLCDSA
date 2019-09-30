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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N);
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int Q;
    cin >> Q;
    vector<int> v(Q), d(Q), c(Q);
    rep(i, 0, Q) {
        cin >> v[Q - i - 1] >> d[Q - i - 1] >> c[Q - i - 1];
        v[Q - i - 1]--;
    }

    vector<vector<bool> > used(N, vector<bool>(11, false));
    vector<int> ans(N);

    function<void(int, int, int)> func = [&](int vv, int dd, int cc) {
        if (used[vv][dd]) return;
        used[vv][dd] = true;
        if (dd == 0) {
            ans[vv] = cc;
            return;
        }
        func(vv, dd - 1, cc);
        for (auto child : G[vv]) {
            func(child, dd - 1, cc);
        }
    };

    rep(i, 0, Q) {
        func(v[i], d[i], c[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }


    return 0;
}