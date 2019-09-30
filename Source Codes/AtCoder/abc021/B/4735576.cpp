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

int check(int *P, int size, int c) {}

int main() {
  int N;
  cin >> N;
  int a, b;
  cin >> a >> b;
  int K;
  cin >> K;
  int P[K];
  REP(i, K) { cin >> P[i]; }

  REP(i, K) {
    if (P[i] == a || P[i] == b) {
      cout << "NO" << endl;
      return 0;
    }
  }

  REP(j, K - 1) {
    FOR(i, j + 1, K) {
      if (P[i] == P[j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;

  return 0;
} ./Main.cpp:55:37: warning: control reaches end of non-void function [-Wreturn-type]
int check(int *P, int size, int c) {}
                                    ^
1 warning generated.