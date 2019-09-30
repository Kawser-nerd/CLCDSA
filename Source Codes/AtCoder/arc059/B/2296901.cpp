#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
  string s;
  cin >> s;

  for (int i = 0; i+1 < s.length(); ++i) {
    if (s[i] == s[i+1]) {
      cout << i+1 << ' ' << i+2 << endl;
      return 0;
    }
  }

  for (int i = 0; i+2 < s.length(); ++i) {
    if (s[i] == s[i+2]) {
      cout << i+1 << ' ' << i+3 << endl;
      return 0;
    }
  }

  cout << -1 << ' ' << -1 << endl;
  return 0;
}