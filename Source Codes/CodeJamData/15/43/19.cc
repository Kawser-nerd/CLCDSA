#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<int> VI;
typedef vector<VI> VVI;
const ll INF = 1000000000000000000LL;

#define VEI(w,e) ((E[e].u == w) ? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge {
    int u, v;
    ll cap[2], flow;
};

VI d, act;

bool bfs(int s, int t, VVI& adj, vector<Edge>& E) {
    queue<int> Q;
    d = VI(adj.size(), -1);
    d[t] = 0;
    Q.push(t);
    while (not Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < int(adj[u].size()); ++i) {
            int e = adj[u][i], v = VEI(u, e);
            if (CAP(v, e) > 0 and d[v] == -1) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    return d[s] >= 0;
}

ll dfs(int u, int t, ll bot, VVI& adj, vector<Edge>& E) {
    if (u == t) return bot;
    for (; act[u] < int(adj[u].size()); ++act[u]) {
        int e = adj[u][act[u]];
        if (CAP(u, e) > 0 and d[u] == d[VEI(u, e)] + 1) {
            ll inc = dfs(VEI(u, e), t, min(bot, CAP(u, e)), adj, E);
            if (inc) {
                ADD(u, e, inc);
                return inc;
            }
        }
    }
    return 0;
}

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
    for (int i = 0; i < int(E.size()); ++i) E[i].flow = 0;
    ll flow = 0, bot;
    while (bfs(s, t, adj, E)) {
        act = VI(adj.size(), 0);
        while ((bot = dfs(s, t, INF, adj, E))) flow += bot;
    } 
    return flow;
}

map<string, int> words;

int get_id(const string& s) {
  if (words.count(s) != 0) {
    return words[s];
  }
  int t = words.size();
  words[s] = t;
  return t;
}

int N;
VVI adjacencies;
vector<Edge> arestes;
void aresta(int u, int v, ll f) {
  int id = arestes.size();
  Edge e;
  e.u = u;
  e.v = v;
  e.cap[0] = f;
  e.cap[1] = 0;
  arestes.push_back(e);
  adjacencies[u].push_back(id);
  adjacencies[v].push_back(id);
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    words.clear();
    int n;
    cin >> n;
    string line;
    Mi sentences;
    getline(cin, line);
    for (int i = 0; i < n; ++i) {
      Vi sentence;
      getline(cin, line);
      stringstream ss(line);
      string s;
      while (ss >> s) {
        sentence.push_back(get_id(s));
      }
      sentences.push_back(sentence);
    }
    
    int m = words.size();

    N = n + 2*m + 2;
    adjacencies = VVI(N);
    arestes.clear();

    for (int i = 0; i < n; ++i) {
      ll f = 100000;
      if (i == 0) f = 0;
      else if (i == 1) f = 10000000000LL;
      aresta(N - 2, i, f);
    }

    for (int i = 0; i < n; ++i) {
      ll f = 100000;
      if (i == 0) f = 10000000000LL;
      else if (i == 1) f = 0;
      aresta(i, N - 1, f);
    }

    for (int i = 0; i < m; ++i) {
      aresta(n + i, n + m + i, 1);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < int(sentences[i].size()); ++j) {
        int k = sentences[i][j];
        aresta(i, n + k, 10000000000LL);
        aresta(n + m + k, i, 10000000000LL);
      }
    }

    ll mf = maxflow(N - 2, N - 1, adjacencies, arestes);
    ll res = mf - (n - 2)*100000LL;

    cout << "Case #" << cas << ": " << res << endl;
  }
}
