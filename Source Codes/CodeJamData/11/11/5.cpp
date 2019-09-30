#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "A"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b) {
  if (!b) {
    return a;
  }
  return gcd(b, a % b);
}

bool can(ll n, ll pd, ll pg) {
  if (pg == 100 && pd != 100) {
    return false;
  }
  if (pg == 0 && pd != 0) {
    return false;
  }
  int nod = gcd(pd, 100);
  int d = 100 / nod;
  if (d <= n) {
    return true;
  }
  return false;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    ll n, pd, pg;
    cin >> n >> pd >> pg;
    cout << "Case #" << test_index + 1 << ": ";
    if (can(n, pd, pg)) {
      cout << "Possible" << endl;
    } else {
      cout << "Broken" << endl;
    }
  }
  return 0;
}
