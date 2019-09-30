#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
  int n;
  cin >> n;
  multiset<int> a;
  rep(i, n) {
    int x;
    cin >> x;
    a.insert(- x);
  }
  int ans = 0;
  while(!a.empty()) {
    auto it = a.begin();
    int x = - (*it);
    a.erase(it);
    int y = - 1;
    rep(i, 33) {
      if (x < (1 << i)) {
        y = (1 << i) - x;
        break;
      }
    }
    if (a.find(- y) == a.end()) continue;
    a.erase(a.find(- y));
    ans++;
  }
  cout << ans << endl;
  return 0;
}