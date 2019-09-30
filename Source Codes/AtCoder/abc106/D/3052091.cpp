#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MAX_N 500
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

multiset< int > graph[MAX_N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  int l[m], r[m];
  for(int i = 0; i < m; i++){
    cin >> l[i] >> r[i];
    --l[i]; --r[i];
  }
  int p1[q], p2[q];
  for(int i = 0; i < q; i++){
    cin >> p1[i] >> p2[i];
    --p1[i];  --p2[i];
  }

  for(int i = 0; i < m; i++){
    graph[l[i]].insert(r[i]);
  }

  int dp[MAX_N][MAX_N];
  for(int i = 0; i < MAX_N; i++){
    fill(dp[i], dp[i] + MAX_N, 0);
  }

  for(int i = 0; i < n; i++){
    dp[i][i] = graph[i].count(i);
  }

  for(int d = 1; d < n; d++){
    for(int i = 0; i + d < n; i++){
      int j = i + d;
      dp[i][j] = dp[i + 1][j] +
        distance(graph[i].begin(),
            graph[i].upper_bound(j));
    }
  }

  string buf;
  for(int i = 0; i < q; i++){
    buf += to_string(dp[p1[i]][p2[i]]) + "\n";
  }

  cout << buf;

  return 0;
}