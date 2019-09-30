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
ll N;
ll A[MAX_N+1];
ll S[MAX_N+1];

int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i];

  ll Asum = 0, sum = 0;
  for (int i =  1; i <= N; ++i) Asum += A[i];
  if ((2*Asum)%(N*(N+1)) != 0) {
    cout << "NO" << endl;
    return 0;
  } else {
    sum = (2*Asum)/(N*(N+1));
  }

  for (int i = 1; i < N; ++i) {
    if (sum-A[i+1]+A[i] < 0 || (sum-A[i+1]+A[i])%N != 0) {
      cout << "NO" << endl;
      return 0;
    } else {
      S[i] = (sum-A[i+1]+A[i])/N;
    }
  }

  if (sum-A[1]+A[N] < 0 || (sum-A[1]+A[N])%N != 0) {
    cout << "NO" << endl;
    return 0;
  } else {
    S[N] = (sum-A[1]+A[N])/N;
  }

  ll accum_S = 0;
  for (int i = 1; i <= N; ++i) accum_S += S[i];

  if (accum_S == sum) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}