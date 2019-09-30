#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;
using std::stack;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long ll;
const ll INF = 1e18 + 9UL;

class edge {
   public:
    ll from;
    ll to;
    ll cost;

    edge() {}
    edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost){};
};

vector<ll> solve(ll n, const vector<edge>& es, ll s) {
    vector<ll> d(n, INF);
    d[s] = 0;

    for (ll i = 0; i < n; i++) {
        bool update = false;

        for (const edge& e : es) {
            if (d[e.from] != INF && d[e.from] + e.cost < d[e.to]) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }

        if (!update) {
            break;
        }
    }

    vector<bool> neg(n);
    for(int i = 0; i < n; i++){
        for(const edge &e : es){
            if(d[e.from] == INF){
                continue;
            }
            if(d[e.from] + e.cost < d[e.to]){
                d[e.to] = d[e.from] + e.cost;
                neg[e.to] = true;
            }
            if(neg[e.from]){
                neg[e.to] = true;
            }
        }
    }

    return neg[n-1] ? vector<ll>(0) : d;
}

/*
vector<bool> dfs(int n, const vector<edge>& es, int s) {
    vector<bool> visited(n);

    stack<int> stack;
    stack.push(s);
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        for (const edge& e : es) {
            if (e.from == v && !visited[e.to]) {
                stack.push(e.to);
            }
        }
    }

    return visited;
}
*/

int main() {
    ll n, m;
    cin >> n >> m;

    vector<edge> es(m);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        es[i] = edge(a - 1, b - 1, -c);
    }

    /*
    vector<bool> visited = dfs(n, es, 0);
    for(size_t i = 0; i < es.size(); i++){
        if(!visited[es[i].to] || !visited[es[i].from]){
            es.erase(es.begin() + i);
        }
    }
    */

    vector<ll> d = solve(n, es, 0);
    if (d.empty()) {
        cout << "inf" << endl;
    } else {
        cout << -d[n - 1] << endl;
    }

    return 0;
}