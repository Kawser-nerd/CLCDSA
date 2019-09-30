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

const int MAX_N = 100000;
int N, L, Q;
int x[MAX_N];
int r[20][MAX_N];

int can_reach(int i, int d) {
  if (d == 0) return i;
  int k = 0;
  while (d >= (1<<k)) ++k;
  --k;
  return can_reach(r[k][i], d-(1<<k));
}

int main() {
  cin >> N;
  rep(i,N) cin >> x[i];
  cin >> L >> Q;

  for (int i = 0; i < N; ++i) {
    r[0][i] = upper_bound(x, x+N, x[i]+L) - x - 1;
  }

  int K = 0;
  while (N >= (1<<K)) ++K;
  for (int k = 1; k < K; ++k) {
    for (int i = 0; i < N; ++i) {
      r[k][i] = r[k-1][r[k-1][i]];
    }
  }


  while (Q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    if (a > b) swap(a,b);

    int lb = 0, ub = N, d = 0;
    while (ub-lb > 1) {
      d = (ub+lb)/2;
      if (can_reach(a, d) >= b) ub = d;
      else lb = d;
    }
    printf("%d\n", ub);
  }

  return 0;
}