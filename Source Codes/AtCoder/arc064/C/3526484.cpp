#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //?????(???????1???)
        x = (x * x) % MOD;
        n >>= 1; //????(n = n >> 1)
    }
    return res;
}

struct Edge{
    int from, to;
    double cost;
};

template <typename T>
vector<T> dijkstra(vector<vector<Edge>> &G, int s) {
    int V = G.size();
    vector<T> d(V); fill(d.begin(), d.end(), numeric_limits<T>::max());
    priority_queue<pair<T, int> , vector< pair<T, int> >, greater< pair<T, int> > > que;
    d[s] = 0;
    que.push(make_pair(0,s));

    while(!que.empty()) {
        pair<T, int> p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++) {
            Edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d;
}

double x[1005];
double y[1005];
double r[1005];
double v[1005];
vector<vector<Edge>> G(1005);

int main(){
    cin.tie(0);

    cin >> x[0] >> y[0] >> x[1] >> y[1];
    r[0] = r[1] = 0;

    int N; cin >> N;
    for (int i = 2; i < N+2; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < N+2; i++){
        for (int j = 0; j < N+2; j++){
            if (i == j) continue;
            Edge e;
            double len = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - r[i] - r[j];
            len = len > 0.0 ? len : 0.0;
            e.cost = len;
            e.to = j;
            G[i].push_back(e);
        }
    }

    vector<double> ans = dijkstra<double>(G, 0);
    printf("%.12f\n", ans[1]);

}