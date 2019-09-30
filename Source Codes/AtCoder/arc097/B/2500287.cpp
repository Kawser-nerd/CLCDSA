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
//#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
//#define EXIST(s, e) ((s).find(e)!=(s).end())
//#define SORT(c) sort(begin(c),end(c))
//#define pb emplace_back
//#define MP make_pair
//#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    rep(i, 0, N) {
        cin >> p[i];
        p[i]--;
    }

    vector<pair<int, int> > vp(M);
    rep(i, 0, M) {
        cin >> vp[i].first >> vp[i].second;
        vp[i].first--;
        vp[i].second--;
    }

    UnionFind uf(N);

    for (int i = 0; i < M; i++) {
        uf.unite(vp[i].first, vp[i].second);
    }

    vector<vector<int> > gr(N);
    for (int i = 0; i < N; i++) {
        int grp = uf.find(i);
        gr[grp].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        //????
        vector<int> moto;
        vector<int> risou;

        for (int j = 0; j < gr[i].size(); j++) {
            moto.push_back(p[gr[i][j]]);
            risou.push_back(gr[i][j]);
        }
        sort(all(moto));
        sort(all(risou));
        int cm = 0;
        int cr = 0;
        while (true) {
            if (cm >= gr[i].size() || cr >= gr[i].size()) {
                break;
            }
            if (moto[cm] == risou[cr]) {
                cm++;
                cr++;
                ans++;
            } else if (moto[cm] < risou[cr]) {
                cm++;
            } else if (moto[cm] > risou[cr]) {
                cr++;
            }


        }
    }
    cout << ans << endl;


    return 0;
}