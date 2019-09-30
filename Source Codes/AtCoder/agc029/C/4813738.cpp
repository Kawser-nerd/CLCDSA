#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define INF 1000000007

void p(vec<int> a)
{
  rep(i, a.size()) cout << a[i] << endl;
  return;
}

bool check(vec<int> a, int k)
{
  map<int, int> s;
  s[a[0] - 1] = 1;
  rep(i, a.size() - 1) {
    if (a[i + 1] > a[i]) {
      s[a[i + 1] - 1] = 1;
    } else {
      if (k == 1) return false;
      int cur = a[i + 1] - 1;
      while(cur >= 0) {
        int temp = s.find(cur) == end(s) ? 1 : s[cur];
        temp++;
        if (temp <= k) {
          s[cur] = temp;
          break;
        }
        s[cur] = 1;
        cur--;
      }
      if (cur < 0) return false;
    }
    auto it = s.find(a[i + 1] - 1);
    it++;
    s.erase(it, end(s));
  }
  return true;
}

int main(void)
{
  int n;
  cin >> n;
  vec<int> a(n);
  rep(i, n) cin >> a[i];

  int left = 1, right = n;
  while(left < right) {
    int mid = (left + right) / 2;
    if (check(a, mid)) right = mid;
    else left = mid + 1;
  }
  cout << left << endl;
  return 0;
}