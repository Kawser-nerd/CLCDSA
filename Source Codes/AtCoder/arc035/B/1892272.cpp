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
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 10000, MOD = 1e9+7;
int N;
int T[MAX_N];
unsigned long long fact[MAX_N+1];

int main() {
  cin >> N;
  rep(i, N) cin >> T[i];

  fact[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fact[i] = (fact[i-1]*i)%MOD;
  }

  unsigned long long mc = 0, comb = 1, nt = 0, time = 0;
  sort(T, T+N);
  for (int i = 0; i < N; ++i) {
    time += T[i];
    mc += time;
  }
  int i = 0;
  while (i < N) {
    int t = upper_bound(T, T+N, T[i]) - lower_bound(T, T+N, T[i]);
    nt += T[i]*t;
    comb = (comb*fact[t])%MOD;
    i += t;
  }

  cout << mc << endl;
  cout << comb << endl;

  return 0;
}