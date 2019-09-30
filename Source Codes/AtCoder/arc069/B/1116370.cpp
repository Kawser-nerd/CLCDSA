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

int main() {
  int n;
  cin >> n;
  string s_;
  cin >> s_;
  vi s(n, 0);
  rep (i, n) {
    if (s_[i] == 'x') {
      s[i] = 1;
    }
  }
  vi a(n, 0);
  rep (i, 4) {
    a[0] = i/2;
    a[1] = (i&1);
    FOR (j, 2, n) {
      a[j] = a[j-2] ^ ((s[j-1] + a[j-1]) % 2);
    }
    if ((((a[n-2] ^ a[0]) ^ a[n-1]) == s[n-1]) && (((a[n-1] ^ a[1]) ^ a[0]) == s[0])) {
      rep (i, n) {
        char tmp;
        if (a[i] == 0) {
          tmp = 'S';
        } else {
          tmp = 'W';
        }
        printf("%c", tmp);
      }
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");

  return 0;
}