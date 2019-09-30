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

const int MAX_N = 100000, MAX_K = 1000;
int N, K;
int x[MAX_N], y[MAX_N];
char c[MAX_N];
int field[MAX_K+1][2*MAX_K+1];


// n????????????
int BIT[2*MAX_K+1], n;

int sum(int i) {
  int res = 0;
  while (i > 0) {
    res += BIT[i];
    i -= i & (-i);
  }
  return res;
}


void add(int i, int x) {
  while (i <= n) {
    BIT[i] += x;
    i += i & (-i);
  }
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> K;
  rep(i, N) cin >> x[i] >> y[i] >> c[i];
  n = 2*K;
  
  for (int i = 0; i < N; ++i) {
    if (((x[i]/K)+(y[i]/K)+(c[i] == 'W' ? 0 : 1))%2 == 0) {
      x[i] = x[i]%K; y[i] = y[i]%K;
    } else {
      x[i] = x[i]%K+K; y[i] = y[i]%K;
    }
  }


  for (int i = 0; i < N; ++i) {
    if (x[i] < K) {
      field[0][0]++;
      field[0][x[i]+1]--;
      field[0][x[i]+K+1]++;
      field[y[i]+1][0]--;
      field[y[i]+1][x[i]+1] += 2;
      field[y[i]+1][x[i]+K+1] -= 2;
    } else {
      field[0][x[i]-K+1]++;
      field[0][x[i]+1]--;
      field[y[i]+1][0]++;
      field[y[i]+1][x[i]-K+1] -= 2;
      field[y[i]+1][x[i]+1] += 2;
    }
  }

 int ans = 0;
 for (int k = 0; k < K; ++k) {
   for (int i = 0; i < 2*K; ++i) {
     add(i+1, field[k][i]);
     ans = max(ans, sum(i+1));
   }
 }

 cout << ans << endl;
 return 0;
}