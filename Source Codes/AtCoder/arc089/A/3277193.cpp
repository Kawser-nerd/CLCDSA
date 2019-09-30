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


const int MAX_N = 100000;
int N;
int t[MAX_N+1], x[MAX_N+1], y[MAX_N+1];


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> t[i] >> x[i] >> y[i];

  for (int i = 0; i < N; ++i) {
    int dst = abs(x[i]-x[i+1]) + abs(y[i]-y[i+1]);
    int peri = t[i+1] - t[i];
    if (dst > peri || (peri-dst)%2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}