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
  int sl = s.length();
  reverse(all(s));

  int ans = 0;
  for (int i = 0; i < sl; ++i) {
    ans += s[i]-'0';
  }

  for (int i = 0; i+1 < sl; ++i) {
    s[i] = '9';
    if (s[i+1] != '0') {
      s[i+1]--;
      int tmp = 0;
      for (int j = 0; j < sl; ++j) {
        tmp += s[j]-'0';
      }
      ans = max(ans, tmp);
    }
  }

  cout << ans << endl;
}