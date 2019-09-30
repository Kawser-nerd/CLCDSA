#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

vector<string> player = {"First\n", "Second\n"};

int n;
vi a;
void execute_gcd() {
  int ret = a[0];
  FOR (i, 1, n) {
    ret = __gcd(ret, a[i]);
  }
  if (ret == 1) {
    return;
  }
  rep (i, n) {
    a[i] /= ret;
  }
}

void judge(int turn) {
  int odd, even;
  odd = even = 0;
  rep (i, n) {
    if ((a[i]&1) == 1) {
      odd += 1;
    } else {
      even += 1;
    }
  }
  if ((even&1) == 1) {
    cout << player[turn];
    exit(0);
  }
  if (odd > 1) {
    cout << player[1 - turn];
    exit(0);
  }
  rep (i, n) {
    if ((a[i]&1) == 1) {
      if (a[i] == 1) {
        cout << player[1 - turn];
        exit(0);
      }
      a[i] -= 1;
      execute_gcd();
      return;
    }
  }
}

int main() {
  scanf("%d", &n);
  a.resize(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }

  int turn = 0;
  while (true) {
    judge(turn);
    turn = 1 - turn;
  }

  return 0;
}