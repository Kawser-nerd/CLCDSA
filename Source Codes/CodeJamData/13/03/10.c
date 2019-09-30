#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> all;

bool small(string a, string b) {
  if (a.length() != b.length()) return a.length() < b.length();
  for (int i = 0; a[i]; i++)
    if (a[i] < b[i]) return 1;
    else if (a[i] > b[i]) return 0;
  return 0;
}

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int ans = 0;
    char l[999], r[999];
    scanf("%s%s", l, r);
    int i;
    for (i = 0; i < all.size(); i++)
      if (!small(all[i], l)) break;
    for (; i < all.size(); i++)
      if (!small(r, all[i])) ans++;
      else break;
    printf("Case #%d: %d\n", C++, ans);
  }
  return 0;
}
