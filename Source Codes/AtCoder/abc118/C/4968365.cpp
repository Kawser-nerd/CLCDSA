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

ll eculidean(ll a, ll b) {
  ll c = a % b;
  if (c == 0) {
    return b;
  }
  return eculidean(b, c);
}

int main() {
  int N;
  cin >> N;
  ll A[N];
  ll M = 0;

  REP(i, N) { cin >> A[i]; }

  ll e = A[0];
  FOR(i, 1, N) {
    ll big = max(e, A[i]);
    ll lit = min(e, A[i]);
    e = eculidean(big, lit);
  }

  cout << e << endl;

  return 0;
}