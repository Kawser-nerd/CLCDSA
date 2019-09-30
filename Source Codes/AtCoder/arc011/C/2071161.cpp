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
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

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
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007

//????????
bool check(string a, string b) {
    int diff = 0;
    rep(i, 0, a.size()) {
        diff += (a[i] != b[i]);
    }
    return diff == 1;
}

class Dijkstra {
public:
    struct edge {
        ll to, cost;
    };
    typedef pair<ll, ll> P;//first??????second??????

    int V;//???
    vector<vector<edge> > G;//???,G[i]?i????????,G[i][j]?i??????j????
    vector<ll> d; //????
    vector<int> prev;

    //0origin
    Dijkstra(int N) {
        V = N;
        G = vector<vector<edge> >(N);
        d = vector<ll>(N);
        prev = vector<int>(N, -1);
    };

    void dijkstra(int s) {
        priority_queue<P, vector<P>, greater<P> > que;
        fill(d.begin(), d.end(), INFl);
        d[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            ll v = p.second;
            if (d[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                edge e = G[v][i];
                if (d[e.to] > d[v] + e.cost && !(d[e.to] == INFl && d[v] == INFl)) {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                    prev[e.to] = v;
                }
            }
        }

    }

    /* ??from???to???????cost????? */
    void addEdge(int from, int to, int cost) {
        edge e;
        e.to = to;
        e.cost = cost;
        G[from].push_back(e);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string first, last;
    cin >> first >> last;
    int N;
    cin >> N;
    int sk = -1, tk = -1;
    int cnt = 0;
    map<string, int> mp;
//    rep(i,0,N){
//        string s;
//        cin >> s;
//        if(s == first) sk = cnt;
//        else if(s == last) tk = cnt;
//        mp[s] = cnt++;
//    }
//    if(sk == -1 || tk == -1){
//        cout << -1 << endl;
//        return 0;
//    }
    if (first == last) {
        cout << 0 << endl;
        cout << first << endl;
        cout << last << endl;
        return 0;
    }

    mp[first] = cnt++;
    mp[last] = cnt++;

    rep(i, 0, N) {
        string s;
        cin >> s;
        if (mp.find(s) == mp.end()) {
            mp[s] = cnt++;
        }
    }

    vector<string> v;
    for (auto ei : mp) {
        v.push_back(ei.first);
        if (ei.first == first) {
            sk = v.size() - 1;
        } else if (ei.first == last) {
            tk = v.size() - 1;
        }
    }
    Dijkstra dij(v.size());

//    for (auto ei : mp) {
//        for (auto ej : mp) {
//            if (check(ei.first, ej.first)) {
//                dij.addEdge(ei.second, ej.second, 1);
//                dij.addEdge(ej.second, ei.second, 1);
//            }
//        }
//    }
    rep(i, 0, v.size()) {
        rep(j, 0, v.size()) {
            if (check(v[i], v[j])) {
                dij.addEdge(i, j, 1);
                dij.addEdge(j, i, 1);
            }
        }
    }
    dij.dijkstra(sk);
    if(dij.d[tk] == INFl){
        cout << -1 << endl;
        return 0;
    }
    cout << dij.d[tk] - 1 << endl;
    vector<string> anss;
    int cur = tk;
    while(cur != -1){
        anss.push_back(v[cur]);
        cur = dij.prev[cur];
    }
    reverse(all(anss));
    rep(i,0,anss.size()){
        cout << anss[i] << endl;
    }


    return 0;
}