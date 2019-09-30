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
  string kenban = "WBWBWWBWBWBW";
  vector<string> doremi = {
    "Do",
    "Do",
    "Re",
    "Re",
    "Mi",
    "Fa",
    "Fa",
    "So",
    "So",
    "La",
    "La",
    "Si",
  };
  REP(i, kenban.size()) {
    string s = S.substr(0, kenban.size());
    string t = kenban.substr(i, kenban.size() - i) + kenban.substr(0, i);
    if (s == t) {
      std::cout << doremi[i] << std::endl;
      break;
    }
  }
}