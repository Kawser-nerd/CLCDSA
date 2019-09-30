#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 50;
int N;
int A[MAX_N], B[MAX_N];
bool S[MAX_N+1];

ll pow(ll x, ll n) {
  if (n == 0) return 1;
  ll res = pow(x*x, n/2);
  if (n & 1) res *= x;
  return res;
}

const int MAX_V = 51, INF = 1e9;
int V = MAX_V;
int d[MAX_V][MAX_V];

void warshall_floyd() {
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
     for (int j = 0; j < V; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < N; ++i) cin >> B[i];

  fill(S+1, S+50, true);


  for (int i = 49; i >= 0; --i) {

    // i?????true????i???????????
    fill(d[0], d[0]+V*V, INF);
    for (int i = 0; i <= 50; ++i) d[i][i] = 0;
    for (int i = 0; i <= 50; ++i) {
      for (int k = 1; k <= 49; ++k) {
        if (S[k]) { d[i][i%k] = 1; }
      }
    }

    // A[i]??B[i]?????????????
    warshall_floyd();
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      if (d[A[i]][B[i]] >= INF) ok = false;
    }

    // ??????????S[i]?false??????????S[i+1]?true?
    if (!ok) S[i+1] = true;
    S[i] = false;
  }

  if (S[50]) {
    cout << -1 << endl;
  } else {
    ll ans = 0;
    for (int k = 1; k < 50; ++k) if (S[k]) { ans += pow(2, k); }
    cout << ans << endl;
  }

  return 0;
}