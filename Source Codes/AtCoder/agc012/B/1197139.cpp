#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

const int MAX_N = 100100;
vector<int> edges[MAX_N];
int N,M,Q;
bool visited[MAX_N];
int color[MAX_N];
int dp[MAX_N][11];
void color_node(const int idx, int v, int d, int c){
  queue<pii> que;

  que.push(mp(v, 0));
  while (not que.empty()){
    pii pos = que.front();
    que.pop();
    int p = pos.first;
    int dist = pos.second;
    if (dist > d)continue;
    if (visited[p]){
      int tmp = d - dist;
      bool ok = false;
      for (int i = tmp; i <= 10; i++){
          if (dp[p][i] >= 0){
            ok = true;
            break;
          }
      }
      if (ok)continue;
      dp[p][d - dist] = idx;
    }else{
      color[p] = c;
      visited[p] = true;

    }
    dp[p][d - dist] = idx;


    for (const auto &nxt : edges[p]){
      que.emplace(mp(nxt, dist + 1));
    }
  }
}
vector<tuple<int, int, int>> query;
void memo(const int v){
  queue<pii> que;
  que.push(mp(v, 0));
  while (not que.empty()){
    pii pos = que.front();
    que.pop();
    int p = pos.first;
    int dist = pos.second;
    if (dist > 10)continue;
    if (visited[p]){
      int res = INF;
      for (int i = dist; i <= 10; i++){
        if (dp[p][i] == -1)continue;
        res = min(res, dp[p][i]);
      }
      if (res == INF)continue;
      color[p] = get<2>(query[res]);
      dp[p][dist] = res;
      continue;
    }
    visited[p] = true;
    for (const auto &nxt : edges[p]){
      que.emplace(mp(nxt, dist + 1));
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++){
    int a,b;
    scanf("%d %d", &a, &b);
    a--,b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  scanf("%d", &Q);

  for (int i = 0; i < Q; i++){
    int v,d,c;
    scanf("%d %d %d", &v, &d, &c);
    v--;
    query.emplace_back(mt(v, d, c));
    // color_node(v, d, c);
  }
  reverse(query.begin(), query.end());
  for (int i = 0; i < MAX_N; i++){
    for (int j = 0; j < 11; j++){
      dp[i][j] = -1;
    }
  }
  for (int i = 0; i < Q; i++){
    int v,d,c;
    tie(v, d, c) = query[i];
    color_node(i, v, d, c);
  }




  for (int i = 0; i < N; i++){
    if (not visited[i]){
      // cout << "none" << " " << i << endl;
      memo(i);
    }
  }

  for (int i = 0; i < N; i++){
    cout << color[i] << endl;
  }
  return 0;
}