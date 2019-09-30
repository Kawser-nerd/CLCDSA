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
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define repa(X,A,Y) for (int (X) = A;(X) <= (Y);++(X))
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

ll N, A, B;

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> A >> B;
  if (N < A+B-1 || N > A*B) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> ans;
  for (int i = 1; i <= A; ++i) ans.push_back(N-A+i);
  int remain = N-A;
  if (B != 1) {
    int size = remain/(B-1);
    int rest = remain%(B-1);
    for (int i = 1; i <= B-1; ++i) {
      if (i <= rest) {
        for (int i = 1; i <= size+1; ++i) {
          ans.push_back(remain-size-1+i);
        }
        remain -= size+1;
      } else {
        for (int i = 1; i <= size; ++i) {
          ans.push_back(remain-size+i);
        }
        remain -= size;
      }
    }
  }

  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << (i+1 == ans.size() ? '\n' : ' ');

  return 0;
}