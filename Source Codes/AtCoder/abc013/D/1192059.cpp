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
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  vi amida(n);
  rep (i, n) amida[i] = i;

  rep (i, m) {
    int index;
    scanf("%d", &index);
    swap(amida[index-1], amida[index]);
  }
  vi move(n);
  rep (i, n) move[amida[i]] = i;

  unordered_map<int, vi> umv;
  vi group(n, -1);
  vi ans(n);
  rep (i, n) {
    if (group[i] >= 0) continue;
    umv[i] = {i};
    for (int j = move[i]; j != i; j = move[j]) {
      umv[i].push_back(j);
      group[j] = i;
    }
    int sz = umv[i].size();
    int ans_index = d % sz;
    rep (j, sz) {
      ans[umv[i][j]] = umv[i][(ans_index + j) % sz];
    }
  }

  rep (i, n) {
    printf("%d\n", ans[i] + 1);
  }

  return 0;
}