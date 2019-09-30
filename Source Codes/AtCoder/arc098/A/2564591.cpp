#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> ls(n), rs(n);
  ls[0]=0;
  for (int i=1; i<n; ++i) {
    ls[i] = ls[i-1] + (s[i-1]=='W' ? 1 : 0);
  }
  rs[n-1] = 0;
  for (int i=n-2; i>=0; --i) {
    rs[i] = rs[i+1] + (s[i+1]=='E' ? 1 : 0);
  }
  int ans=0xfffffff;
  for (int i=0; i<n; ++i) {
    ans = min(ans, ls[i]+rs[i]);
  }
  cout << ans << endl;
}