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
struct PartiallyPersistentUnionFind {
    vector<int> data;
    vector<int> last;
    vector<vector<pair<int, int> > > add;

    PartiallyPersistentUnionFind() {}

    PartiallyPersistentUnionFind(int sz) : data(sz, -1), last(sz, 1e9), add(sz) {
        for (auto &vs : add) vs.emplace_back(-1, -1);
    }

    bool unite(int t, int x, int y) {
        x = find(t, x);
        y = find(t, y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        add[x].emplace_back(t, data[x]);
        data[y] = x;
        last[y] = t;
        return true;
    }

    int find(int t, int x) {
        if (t < last[x]) return x;
        return find(t, data[x]);
    }

    int size(int t, int x) {
        x = find(t, x);
        return -prev(lower_bound(begin(add[x]), end(add[x]), make_pair(t, 0)))->second;
    }
};

class Solve {
public:
    PartiallyPersistentUnionFind puf;
    int N, M;

    void input() {
        cin >> N >> M;
        puf = PartiallyPersistentUnionFind(N);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            puf.unite(i + 1, a, b); //??????+1????
        }
    }

    // ??????x?y?????
    int sz(int t, int x, int y) {
        if (puf.find(t, x) == puf.find(t, y)) {
            //????
            return puf.size(t, x);
        }
        return puf.size(t, x) + puf.size(t, y);
    }

    void solve() {
        input();
        int Q;
        cin >> Q;
        while (Q--) {
            int x, y, z;
            cin >> x >> y >> z;

            int ok = M;
            int ng = -1;

            while (ok - ng > 1) {
                int mid = (ok + ng) / 2;
                int val = sz(mid, x, y);
                if (val < z) {
                    ng = mid;
                } else {
                    ok = mid;
                }
            }
            cout << ok << endl;
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