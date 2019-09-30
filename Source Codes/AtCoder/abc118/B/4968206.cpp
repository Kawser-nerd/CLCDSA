#include <math.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <ostream>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef int _lcint;
#define REP(i, n) for (_lcint i = 0; i < n; i++)
#define FOR(i, a, b) for (_lcint i = (_lcint)(a); i < (_lcint)(b); i++)
#define FORREV(i, a, b) for (_lcint i = (_lcint)(b)-1; i >= (_lcint)(a); i--)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUG_VEC(v)  \
  cout << #v << ": "; \
  REP(i, v.size()) cout << " " << v[i] << endl;

#define ALL(a) (a).begin(), (a).end()
#define CHMIN(a, b) a = min((a), (b))
#define CHMAX(a, b) a = max((a), (b))

// permutation
ll mPn(ll m, ll n) {
  ll a = 1;
  REP(i, n) { a *= m - i; }
  return a;
}

// excrametion
ll exc(ll m) {
  ll a = 1;
  FOR(i, 1, m) { a *= i + 1; }
  return a;
}

// combination
ll mCn(ll m, ll n) {
  ll a = 1, b = 1;
  REP(i, n) {
    a *= m - i;
    b *= n - i;
  }
  return a / b;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> R(M);
  REP(i, N) {
    int k;
    cin >> k;

    REP(j, k) {
      int a;
      cin >> a;
      R[a - 1]++;
    }
  }

  int count = 0;
  REP(i, M) {
    if (R[i] == N) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}