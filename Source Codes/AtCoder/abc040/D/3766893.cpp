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
class UnionFind {
    vector<int> p;//p[i]?i??????
public:
    UnionFind(int n) {
        p = vector<int>(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        return;
    }

/* x????????? */
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

/* y?x????? */
    void unite(int x, int y) {
        p[find(x)] = p[find(y)];
    }

/* x?y??????????????? */
    bool same(int x, int y) {
        return find(x) == find(y);
    }

};

class Solve {
public:
    void input() {

    }

    void solve() {
        input();
        int N, M;
        cin >> N >> M;
        struct query {
            int type;//0: ?, 1: ??
            int year;
            int first;  //type?0???????, 1??????
            int second; //type?0??id, 1???????????
//            query(int type, int year, int first, int second) :type(type), year(year),
        };
        vector<query> vq;
        for (int i = 0; i < M; ++i) {
            int v, w, year;
            cin >> v >> w >> year;
            vq.push_back(query({1, year, v, w}));
        }

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; ++i) {
            int v, year;
            cin >> v >> year;
            vq.push_back(query({0, year, v, i}));
        }

        sort(all(vq), [](query l, query r) {
            if (l.year != r.year) return l.year > r.year;
            return l.type < r.type;
        });

        UnionFind uf(N + 5);
        vector<int> sz(N + 5, 1);

        vector<pair<int, int>> ans;
        for (auto q : vq) {
            if (q.type) {
                int from = q.first;
                int to = q.second;
                if (!uf.same(from, to)) {
                    sz[uf.find(to)] += sz[uf.find(from)];
                    sz[uf.find(from)] = 0;
                    uf.unite(from, to);
                }
            } else {
//                cout << sz[uf.find(q.first)] << endl;
                ans.push_back(make_pair(q.second, sz[uf.find(q.first)]));
            }
        }

        sort(all(ans));
        for (auto e : ans) {
            cout << e.second << endl;
        }

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}