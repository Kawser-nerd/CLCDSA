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
const int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const double PI = 3.141592653589793238462643383279;


const int MAX_N = 100000;
int N;
int A[MAX_N];

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];

  sort(A, A+N);
  reverse(A, A+N);

  ll a = 0, b = 0;
  for (int i = 0; i < N-1; ++i) {
    if (a != 0 && b != 0) break;
    if (A[i] == A[i+1]) {
      if (a == 0) a = A[i];
      else b = A[i];
      ++i;
    }
  }

  cout << a*b << endl;

  return 0;
}