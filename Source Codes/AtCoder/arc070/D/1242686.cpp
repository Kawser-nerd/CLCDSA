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

bool ask(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  char c;
  scanf(" %c", &c);
  fflush(stdin);
  if (c == 'Y') {
    return true;
  } else {
    return false;
  }
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  fflush(stdin);
  int n = a + b;
  if (a <= b) {
    printf("Impossible\n");
    fflush(stdout);
    return 0;
  }
  deque<int> q;
  rep (i, n) {
    if (q.empty()) {
      q.push_back(i);
      continue;
    }
    if (ask(q.back(), i)) {
      q.push_back(i);
    } else {
      q.pop_back();
    }
  }
  assert(!q.empty());
  vi ans(n, 0);
  int judge = q.back();
  rep (i, n) {
    if (ask(judge, i)) {
      ans[i] = 1;
    }
  }

  printf("! ");
  rep (i, n) {
    printf("%d", ans[i]);
  }
  printf("\n");
  fflush(stdout);

  return 0;
}