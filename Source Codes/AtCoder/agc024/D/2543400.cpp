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
int N;
vector<vector<int> > G;
vector<pair<int, int> > edge;

int cal_hei(int p, int v) {

    if (G[v].size() == 1 && G[v][0] == p) {
        return 1;
    }
    int ret = 1;
    for (auto next : G[v]) {
        if (next != p) {
            ret = max(cal_hei(v, next), ret);
        }
    }

    return ret + 1;
}

ll cal_leaf(int v) {
    set<int> used;
    queue<pair<int, int>> q;//??, ??
    vector<int> level;//?????i????????????

    used.insert(v);
    q.push(pair<int, int>(v, 0));
    level.push_back(G[v].size());

    while (q.size()) {
        auto tmp = q.front();
        q.pop();

        for (auto next : G[tmp.first]) {
            if (used.find(next) == used.end() && G[next].size() != 1) {
                q.push(pair<int, int>(next, tmp.second + 1));
                used.insert(next);
            }
        }

        if (tmp.second >= level.size()) {
            level.push_back(G[tmp.first].size() - 1);
        } else {
            level[tmp.second] = max((int) level[tmp.second], (int) G[tmp.first].size() - 1);
        }
    }

    ll ret = 1LL;
    for (auto e : level) {
        if (e) ret *= e;
    }

    return ret;
}

ll cal_leaf(pair<int, int> hen) {
    set<int> used;
    queue<pair<int, int>> q;//??, ??
    vector<int> level;//?????i????????????

    used.insert(hen.first);
    q.push(pair<int, int>(hen.first, 0));
    level.push_back(G[hen.first].size() - 1);

    used.insert(hen.second);
    q.push(pair<int, int>(hen.second, 0));
//    level.push_back(G[hen.first].size());
    level[0] = max((int) level[0], (int) G[hen.second].size() - 1);

    while (q.size()) {
        auto tmp = q.front();
        q.pop();

        for (auto next : G[tmp.first]) {
            if (used.find(next) == used.end() && G[next].size() != 1) {
                q.push(pair<int, int>(next, tmp.second + 1));
                used.insert(next);
            }
        }

        if (tmp.second >= level.size()) {
            level.push_back(G[tmp.first].size() - 1);
        } else {
            level[tmp.second] = max((int) level[tmp.second], (int) G[tmp.first].size() - 1);
        }
    }

    ll ret = 2LL;
    for (auto e : level) {
        if (e) ret *= e;
    }

    return ret;
}


pair<int, ll> compute_v() {
    vector<int> hei(N);
    int min_h = INF;
    rep(i, 0, N) {
        hei[i] = cal_hei(-1, i);
        min_h = min(min_h, hei[i]);
    }
    ll min_leaf = INFl;
//    for (auto v : hei) {
//        if (hei[v] == min_h) {
//            min_leaf = min(cal_leaf(v), min_leaf);
//        }
//    }
    rep(i, 0, hei.size()) {
        if (hei[i] == min_h) {
            min_leaf = min(cal_leaf(i), min_leaf);
        }
    }
    return pair<int, ll>(min_h, min_leaf);
}

pair<int, ll> compute_e() {
    vector<int> hei(N - 1);
    int min_h = INF;
    rep(i, 0, N - 1) {
        hei[i] = max(cal_hei(edge[i].first, edge[i].second), cal_hei(edge[i].second, edge[i].first));
        min_h = min(hei[i], min_h);
    }
    ll min_leaf = INFl;
//    for (auto hen : hei) {
//        if (hei[hen] == min_h) {
//            min_leaf = min(cal_leaf(edge[hen]), min_leaf);
//        }
//    }
    rep(i, 0, hei.size()) {
        if (hei[i] == min_h) {
            min_leaf = min(cal_leaf(edge[i]), min_leaf);
        }
    }
    return pair<int, ll>(min_h, min_leaf);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    G.resize(N);

    rep(i, 0, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge.emplace_back(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

//    rep(i, 0, N) {
//        cout << cal_hei(-1, i) << endl;
//    }

    auto ans = min(compute_e(), compute_v());

    cout << ans.first << " " << ans.second << endl;


    return 0;
}