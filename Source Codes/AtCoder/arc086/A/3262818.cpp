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

const int MAX_N = 200000;
int N, K;
int A[MAX_N];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> K;
  rep(i, N) cin >> A[i];

  sort(A, A+N);
  vector<Pii> vp;
  int count = 1;
  for (int i = 0; i < N; ++i) {
    if (i+1 == N) {
      vp.push_back(Pii(count, A[i]));
      continue;
    }
    if (A[i] == A[i+1]) ++count;
    else {
      vp.push_back(Pii(count, A[i]));
      count = 1;
    }
  }

  sort(all(vp));
  int ans = 0, size = vp.size();
  for (int i = 0; i < vp.size(); ++i) {
    if (size <= K) break;
    ans += vp[i].fi;
    --size;
  }

  cout << ans << endl;
  return 0;
}