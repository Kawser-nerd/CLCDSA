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
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = (int)s.length();
  for (char c = 'a'; ; c += 1) {
    vi ind;
    rep (i, n) {
      if (s[i] == c) {
        ind.push_back(i);
      }
    }
    int m = (int)ind.size();
    set<string> q;
    FOR (i, 1, 6) {
      rep (j, m) {
        if (ind[j] + i > n) {
          break;
        }
        q.insert(s.substr(ind[j], i));
      }
    }
    if ((int)q.size() < k) {
      k -= (int)q.size();
      continue;
    }
    string ans;
    rep (i, k) {
      ans = *begin(q);
      q.erase(begin(q));
    }
    cout << ans << "\n";
    return 0;
  }
  return 0;
}