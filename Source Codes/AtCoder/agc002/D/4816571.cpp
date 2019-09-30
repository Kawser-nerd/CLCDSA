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
    int N, M;
    vector<pair<int, int>> ab; //edge
    int Q;

    struct query {
        int id;
        int x, y, z;
        int ok, ng;
        int mid;

        query() {}

        query(int id, int x, int y, int z, int ok, int ng) : id(id), x(x), y(y), z(z), ok(ok), ng(ng),
                                                             mid((ok + ng) / 2) {}

        void update_mid() {
            mid = (ok + ng) / 2;
        }

        void update_range(bool flag) {
            if (flag) {
                //???????
                ok = mid;
            } else {
                ng = mid;
            }
        }

    };

    vector<query> queries;

    void input() {
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            ab.emplace_back(a, b);
        }
        cin >> Q;
        for (int i = 0; i < Q; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--;
            query query1(i, x, y, z, M, -1);
            queries.push_back(query1);
        }
    }

    void solve() {
        input();


        for (int _ = 0; _ < 100; _++) {
            //??????100????????

            //query?mid??????, mid?????
            for (auto &q : queries) {
                q.update_mid();
            }
//            for (int i = 0; i < Q; ++i) {
////                queries[i].update_mid();
//                queries[i].mid = (queries[i].ok + queries[i].ng) / 2;
//            }

            sort(all(queries), [](query a, query b) {
                return a.mid < b.mid;
            });

            UnionFind uf(N);
            vector<int> gsize(N, 1);

            int idx = 0;
            for (int i = 0; i < Q; ++i) {
                while (idx < queries[i].mid) {
                    if (!uf.same(ab[idx].first, ab[idx].second)) {
                        gsize[uf.find(ab[idx].second)] += gsize[uf.find(ab[idx].first)];
                        gsize[uf.find(ab[idx].first)] = 0;
                        uf.unite(ab[idx].first, ab[idx].second);
                    }
                    ++idx;
                }
                int x = queries[i].x;
                int y = queries[i].y;
                int z = queries[i].z;

//                int sz = gsize[uf.find(x)] + gsize[uf.find(y)];
                int sz;
                if (uf.same(x, y)) {
                    sz = gsize[uf.find(x)];
//                    queries[i].update_range(z <= sz);
                } else {
                    sz = gsize[uf.find(x)] + gsize[uf.find(y)];
//                    queries[i].update_range(z <= sz);
                }
//                if (z <= sz) {
//                    queries[i].ok = queries[i].mid;
//                } else {
//                    queries[i].ng = queries[i].mid;
//                }
                queries[i].update_range(z <= sz);

            }
        }
        //id?????
        sort(all(queries), [](query a, query b) {
            return a.id < b.id;
        });

        for (auto q : queries) {
            cout << q.ok << endl;
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