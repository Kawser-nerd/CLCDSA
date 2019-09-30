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

string A;
vector<int> alpha[26];
bool apper[26];

int main() {
  cin >> A;
  int N = A.size();
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[j] == 'a'+i) alpha[i].push_back(j);
    }
  }

  for (int i = 0; i < 26; ++i) alpha[i].push_back(N);

  vector<int> S;
  memset(apper, false, 26);
  int count = 0;
  S.push_back(N);
  for (int i = N-1; i >= 0; --i) {
    if (!apper[A[i]-'a']) {
      apper[A[i]-'a'] = true;
      ++count;
    }
    if (count == 26) {
      S.push_back(i);
      count = 0;
      memset(apper, false, 26);
    } else if (i == 0) {
      S.push_back(0);
    }
  }


  reverse(all(S));
  string ans;
  for (int i = 0; i < 26; ++i) {
    if (!apper[i]) {
      ans += 'a'+i;
      break;
    }
  }

  int idx;
  idx = alpha[ans[0]-'a'][0];

  while (idx < N) {
    int ub = *upper_bound(all(S), idx);
    for (int i = 0; i < 26; ++i) {
      int next_char_idx = *upper_bound(all(alpha[i]), idx);
      if (next_char_idx >= ub) {
        ans += 'a'+i;
        idx = next_char_idx;
        break;
      }
    }
  }
  

  cout << ans << endl;

  return 0;
}