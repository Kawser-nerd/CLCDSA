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

class UnionFind {
    vector<int> p;//p[i]?i??????
public:
    UnionFind(int n){
        p = vector<int>(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        return;
    }

    void printState() {
        if (DEBUG) {
            cout << "---" << endl;
            for (int i = 0; i < p.size(); i++) {
                printf("%d???%d\n", i, p[i]);
            }
            cout << "---" << endl;
        }
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

    int N;
    cin >> N;
    vector<pair<ll,ll> > x,y;
    rep(i,1,N+1){
        int a,b;
        cin >> a >> b;
        x.emplace_back(a,i);
        y.emplace_back(b,i);
    }

    sort(all(x));
    sort(all(y));

    vector<pair<ll,pair<ll,ll> > > vp;

    rep(i,0,x.size()-1){
        ll cost = x[i+1].first - x[i].first;
        vp.push_back(make_pair(cost,make_pair(x[i].second,x[i+1].second)));
        vp.push_back(make_pair(cost,make_pair(x[i+1].second,x[i].second)));
    }
    rep(i,0,y.size()-1){
        ll cost = y[i+1].first - y[i].first;
        vp.push_back(make_pair(cost,make_pair(y[i].second,y[i+1].second)));
        vp.push_back(make_pair(cost,make_pair(y[i+1].second,y[i].second)));
    }

    sort(all(vp));

    ll ans = 0LL;
    UnionFind un(N+1);
    rep(i,0,vp.size()){
        int a = vp[i].second.first;
        int b = vp[i].second.second;
        if(!un.same(a,b)){
            un.unite(a,b);
            ans += vp[i].first;
        }
    }

    cout << ans << endl;



    return 0;
}