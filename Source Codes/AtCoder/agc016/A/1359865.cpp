#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); ++i)
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(v) begin(v), end(v)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

int main() {
  std::ios::sync_with_stdio(false);

  string s;
  while(cin >> s){
    string org = s;
    int ans = 100;
    for(char c = 'a'; c <= 'z'; ++c) {
      s = org;

      rep(p, 100) {
        int k = count(all(s), c);
        if (k == 0) {
          break;
        }
        if (k == s.size()) {
          ans = min(ans, p);
          break;
        }

        string t = s.substr(0, s.size() - 1);
        rep(i, s.size() - 1) {
          if (s[i] == c || s[i+1] == c) {
            t[i] = c;
          }
        }
        s = t;
      }
    }
    cout << ans << endl;
  }
  return 0;
}