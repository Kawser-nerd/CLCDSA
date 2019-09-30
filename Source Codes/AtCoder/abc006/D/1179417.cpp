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

int main() {
  int n;
  scanf("%d", &n);
  vi card(n, 0);
  rep (i, n) {
    scanf("%d", &card[i]);
  }
  set<pii> longest;
  longest.insert(make_pair(-1, 0));
  vi lis;
  lis.reserve(n);
  lis.push_back(card[0]);
  FOR (i, 1, n) {
    auto ub = upper_bound(all(lis), card[i]);
    if (ub == end(lis)) {
      lis.push_back(card[i]);
    } else {
      *ub = card[i];
    }
  }
  printf("%d\n", n - (int)lis.size());

  return 0;
}