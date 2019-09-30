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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

string S;

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> S;
  int N = S.size();

  int ans = 0;
  if (N%2 == 0) {
    int mid = N/2;
    int count = 0;
    for (int i = mid-1; i >= 0; --i) {
      if (S[i] == S[2*mid-i-1]) {
        count += 2;
      } else {
        break;
      }
    }
    ans = (N-count)/2 + count;
  } else {
    int mid = N/2;
    int count = 1;
    for (int i = 1; mid-i >= 0; ++i) {
      if (S[mid-i] == S[mid+i] && S[mid] == S[mid-1]) {
        count += 2;
      } else {
        break;
      }
    }
    ans = (N-count)/2 + count;
  }

  cout << ans << endl;

  return 0;
}