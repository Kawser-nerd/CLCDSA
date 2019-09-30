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
class Dijkstra{
public:
    struct edge{ll to; double cost;};
    typedef pair<double,ll> P;//first??????second??????

    int V;//???
    vector<vector<edge> > G;//???,G[i]?i????????,G[i][j]?i??????j????
    vector<double> d; //????

    //0origin
    Dijkstra(int N){
        V = N;
        G = vector<vector<edge> >(N);
        d = vector<double>(N);
    };

    void dijkstra(int s){
        priority_queue<P,vector<P>,greater<P> > que;
        fill(d.begin(),d.end(),INFl);
        d[s] = 0;
        que.push(P(0,s));

        while(!que.empty()){
            P p = que.top();que.pop();
            ll v = p.second;
            if(d[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); i++){
                edge e = G[v][i];
                if (d[e.to] > d[v] + e.cost && !(d[e.to] == INFl && d[v] == INFl)) {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to],e.to));
                }
            }
        }

    }
    /* ??from???to???????cost????? */
    void addEdge(int from,int to,double cost){
        edge e{};
        e.to = to;
        e.cost = cost;
        G[from].push_back(e);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int xs,ys,xt,yt;
    cin >> xs >> ys >> xt >> yt;
    int N;
    cin >> N;
    vector<int> x(N+2),y(N+2),r(N+2);
    rep(i,1,N+1){
        cin >> x[i] >> y[i] >> r[i];
    }
    x[0] = xs;
    y[0] = ys;
    x[N+1] = xt;
    y[N+1] = yt;

    Dijkstra dij(N+2);

    rep(i,0,N+2){
        rep(j,0,N+2){
            double cost = sqrt(pow(x[i] - x[j],2) + pow(y[i] - y[j],2)) - r[i] - r[j];
            if(cost < 0) cost = 0.0;
            dij.addEdge(i,j,cost);
        }
    }

    dij.dijkstra(0);
//    cout << dij.d[N+1] << endl;
    printf("%.9lf\n",dij.d[N+1]);

    return 0;
}