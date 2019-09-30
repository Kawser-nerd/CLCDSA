#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <unordered_map>
#include <array>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <random>
#include <numeric>

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;


const int MAX_N = 100000;
int N;
int a[MAX_N], b[MAX_N];
ll A[MAX_N];
                            
struct edge { int to, cost; };
const int MAX_V = MAX_N, INF = 10000000;

// V??????????
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
  fill(d, d+V, INF);
  priority_queue<Pii, vector<Pii>, greater<Pii> > pque;
  d[s] = 0;
  pque.push(Pii(0, s));


  while (!pque.empty()) {
    Pii p = pque.top(); pque.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < (int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost; 
        pque.push(Pii(d[v]+ e.cost, e.to));
      }
    }
  }
}

ll rec(int v) {
  if (G[v].size() == 1) return A[v];

  vector<ll> vec;
  for (int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i].to;
    if (d[v] > d[u]) continue;
    vec.push_back(rec(u));
  }
  
  ll sum = 0;
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] < 0) return -1;
    sum += vec[i];
  }

  ll res = 2*A[v] - sum;
  if (res < 0) return -1;
  vec.push_back(res);

  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] > A[v]) return -1;
  }

  return res;
}

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N-1) {
    cin >> a[i] >> b[i]; a[i]--; b[i]--;
  }


  V = N;
  for (int i = 0; i < N-1; ++i) {
    G[a[i]].push_back((edge){b[i], 1});
    G[b[i]].push_back((edge){a[i], 1});
  }

  if (N == 2) {
    if (A[0] == A[1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
  }

  int root = 0;
  for (int i = 0; i < N; ++i) {
    if (G[i].size() != 1) {
      root = i; break;
    }
  }

  dijkstra(root);

  if (rec(root) != 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  return 0;
}