#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define repa(X,A,Y) for (int (X) = A;(X) <= (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define mod(n, m) (((n)%(m)+(m))%m)
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

const int MAX_N = 100000, MAX_M = 100000;
int N, M;
int A[MAX_N], B[MAX_N];
                            
struct edge { int to, cost; };
const int MAX_V = 100000, INF = 1e9;

// V??????????
int V;
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int v, int u, int cost) {
  G[v].push_back((edge){u, cost});
  G[u].push_back((edge){v, cost});
}

void dfs(int v, vector<int> &vec) {
  vec.push_back(v);
  used[v] = true;

  for (int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i].to;
    if (!used[u]) {
      dfs(u, vec); break;
    }
  }

  return;
}


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> M;
  rep(i, M) cin >> A[i] >> B[i];
  rep(i, M) {--A[i]; --B[i];}
  V = N;

  rep(i, M) add_edge(A[i], B[i], 1);

  vector<int> vec1, vec2;
  dfs(0, vec1);

  for (int i = 0; i < G[0].size(); ++i) {
    int u = G[0][i].to;
    if (!used[u]) {
      dfs(u, vec2); break;
    }
  }

  reverse(all(vec1));
  
  cout << vec1.size() + vec2.size() << endl;
  for (int i = 0; i < vec1.size(); ++i) {
    cout << vec1[i]+1 << (i+1 == vec1.size() && vec2.size() == 0 ? '\n' : ' ');
  }
  for (int i = 0; i < vec2.size(); ++i) {
    cout << vec2[i]+1 << (i+1 == vec2.size() ? '\n' : ' ');
  }

  return 0;
}