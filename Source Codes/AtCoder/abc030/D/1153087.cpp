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

string k;
int size_mod;
int calculate_remainder(int offset) {
  int l = (int)k.length();
  int ret = 0;
  rep (i, l) {
    ret *= 10;
    ret += (k[i] - '0');
    ret %= size_mod;
  }
  ret -= offset;
  while (ret < 0) {
    ret += size_mod;
  }
  return ret;
}

int main() {
  int n, a;
  scanf("%d %d", &n, &a);
  a -= 1;
  cin >> k;
  vi b(n, 0);
  rep (i, n) {
    scanf("%d", &b[i]);
    b[i] -= 1;
  }

  vi route = {a};
  route.reserve(1e5);
  set<int> appeared;
  appeared.insert(a);
  while (true) {
    route.push_back(b[route.back()]);
    if (appeared.find(route.back()) != end(appeared)) {
      break;
    } else {
      appeared.insert(route.back());
    }
  }

  if ((int)k.length() < 9) {
    int k_i = stoi(k);
    if (k_i < (int)route.size()) {
      printf("%d\n", route[k_i] + 1);
      return 0;
    }
  }

  int ind = 0;
  rep (i, n) {
    if (route[i] == route.back()) {
      ind = i;
      break;
    }
  }
  size_mod = (int)route.size() - 1 - ind;
  int ans = calculate_remainder(ind);
  printf("%d\n", route[ind + ans] + 1);

  return 0;
}