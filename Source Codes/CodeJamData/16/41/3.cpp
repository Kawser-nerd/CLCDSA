#include <bits/stdc++.h>

using namespace std;

const string IMP = "IMPOSSIBLE";

string go(int n, int p, int r, int s) {
  if (n == 0) {
    return (p > 0 ? "P" : (r > 0 ? "R" : "S"));
  }
  int x =  p + r - s;
  int y = -p + r + s;
  int z =  p - r + s;
  if (x < 0 || y < 0 || z < 0) {
    return IMP;
  }
  if (x % 2 != 0 || y % 2 != 0 || z % 2 != 0) {
    return IMP;
  }
  x /= 2;
  y /= 2;
  z /= 2;
  string res = go(n - 1, x, y, z);
  if (res == IMP) {
    return IMP;
  }
  string ans = "";
  for (int i = 0; i < (int) res.length(); i++) {
    char c = res[i];
    if (c == 'P') {
      ans += "PR";
    }
    if (c == 'R') {
      ans += "RS";
    }
    if (c == 'S') {
      ans += "PS";
    }
  }
  return ans;
}

string enhance(string s) {
  if (s == IMP) {
    return s;
  }
  int len = s.length();
  if (len == 1) {
    return s;
  }
  string x = s.substr(0, len / 2);
  string y = s.substr(len / 2);
  x = enhance(x);
  y = enhance(y);
  if (x > y) {
    swap(x, y);
  }
  return x + y;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, r, p, s;
    scanf("%d %d %d %d", &n, &r, &p, &s);
    printf("%s\n", enhance(go(n, p, r, s)).c_str());
  }
  return 0;
}
