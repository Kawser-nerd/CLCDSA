#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define F first
#define S second
#define PII pair<int, int>
typedef long long LL;


using namespace std;

const int N = 1e5 + 10;
const LL INF = 1e16;
vector<LL> v;
LL n, a[N], r[N], ans;
map<int, bool> mp;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2)
      mp[a[i]] = true;
    r[i] = a[i];
  }
  sort(r, r + n);
  for (int i = 0; i < n; i++) {
    if (i % 2 && !mp[r[i]])
      ans++;
  }
  cout << ans;
  return 0;
}