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
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define _size(X) (int)((X).size())
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

string s;
bool used[26];

bool judge(string str) {
    for (int i = 0; i+1 < str.size(); ++i) {
        if (str[i] != str[i+1]) return false;
    }
    return true;
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
      used[s[i]-'a'] = true;
  }

  int ans = INFINT;
  for (int i = 0; i < 26; ++i) {
      if (used[i]) {
          string tmp_s = s;
          int tmp = 0;
          while (!judge(tmp_s)) {
              for (int j = 0; j+1 < tmp_s.size(); ++j) {
                  if (tmp_s[j] == i+'a' || tmp_s[j+1] == i+'a') {
                      tmp_s[j] = i+'a';
                  }
              }
              tmp_s.resize(tmp_s.size()-1);
              ++tmp;
          }
          ans = min(ans, tmp);
      }
  }


  cout << ans << endl;

  return 0;
}