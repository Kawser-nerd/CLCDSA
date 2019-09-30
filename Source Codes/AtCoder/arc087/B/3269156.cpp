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

const int MAX_S = 8000;
bool dp[MAX_S+1][MAX_S+1];
int size;
string S;
int x, y;


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> S;
  cin >> x >> y;
  size = S.size();

  bool first = false;
  vector<int> xv,yv;
  int count = 0, tmp = 0;
  for (int i = 0; i < size; ++i) {
    if (S[i] == 'F') ++tmp;
    if (S[i] == 'T' || i+1 == size) {
      if (count%2 == 0) xv.push_back(tmp);
      else yv.push_back(tmp);
      tmp = 0;
    }
    if (S[i] == 'T') ++count;
  }

  bool judge;
  if (xv.size() == 1) {
    if (x == xv[0]) judge = true;
    else judge = false;
  } else {
    dp[1][xv[1]] = true;
    for (int i = 2; i < xv.size(); ++i) {
      for (int j = 0; j <= size; ++j) {
        dp[i][j] = dp[i-1][abs(j-xv[i])];
        if (abs(j+xv[i]) <= size) dp[i][j] |= dp[i-1][abs(j+xv[i])];
      }
    }
    judge = dp[xv.size()-1][abs(x-xv[0])];
  }


  if (yv.size() == 0) {
    if (judge && y == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }

  memset(dp, false, sizeof(dp));
  dp[0][yv[0]] = true;
  for (int i = 1; i < yv.size(); ++i) {
    for (int j = 0; j <= size; ++j) {
      dp[i][j] = dp[i-1][abs(j-yv[i])];
      if (abs(j+yv[i]) <= size) dp[i][j] |= dp[i-1][abs(j+yv[i])];
    }
  }
  judge &= dp[yv.size()-1][abs(y)];

  if (judge) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}