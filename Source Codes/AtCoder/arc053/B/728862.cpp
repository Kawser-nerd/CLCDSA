#include <stdint.h>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);
static const ll MOD = 1000000007;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout << #x << ": " << x << endl

int main() {
  string S;
  cin >> S;
  vector<int> count(26, 0);
  REP(i, S.size()) {
    count[S[i] - 'a']++;
  }
  vector<int> odd;
  int even = 0;
  REP(i, 26) {
    if (count[i] % 2 == 0) {
      even += count[i] / 2;
    } else {
      while (count[i] >= 2) {
        even++;
        count[i] -= 2;
      }
      odd.push_back(count[i]);
    }
  }
  if (odd.size() == 0) {
    odd.push_back(0);
  } else {
    sort(ALL(odd));
  }
  while (even > 0) {
    odd[0] += 2;
    even--;
    sort(ALL(odd));
  }
  std::cout << odd[0] << std::endl;
}