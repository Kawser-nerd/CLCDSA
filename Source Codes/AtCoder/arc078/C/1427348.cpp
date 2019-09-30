#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

bool question(ll n) {
  printf("? %lld\n", n);
  fflush(stdout);
  char c;
  scanf(" %c", &c);
  fflush(stdin);
  if (c == 'Y') {
    return true;
  } if (c == 'N') {
    return false;
  }
  assert (false);
}

void print_ans(ll n) {
  printf("! %lld\n", n);
  fflush(stdout);
  exit(0);
}

ll po10(int k) {
  ll ret = 1;
  rep (i, k) {
    ret *= 10;
  }
  return ret;
}

int main() {
  int ds = 1;
  for ( ;ds <= 9 ; ++ds) {
    if (!question(po10(ds))) {
      break;
    }
    if (ds == 9) {
      ll ans = 0;
      rep (i, 10) {
        ans += 5 * po10(i);
        if (question(ans)) {
          print_ans(po10(i));
        }
      }
      assert (false);
    }
  }
  ll l = po10(ds - 1);
  ll r = po10(ds) - 1;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (question(mid * 10)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  print_ans(r);

  return 0;
}