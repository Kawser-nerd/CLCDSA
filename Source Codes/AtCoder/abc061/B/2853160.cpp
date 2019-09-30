#include <iostream>

using namespace std;

int main()
{
  int n, m; cin >> n >> m;
  int cnt[n + 1];
  // ???
  for (int i = 1; i <= n; i++) cnt[i] = 0;

  for (int i = 1; i <= m; i++) {
    int a, b; cin >> a >> b;
    cnt[a] += 1;
    cnt[b] += 1;
  }

  for (int i = 1; i <= n; i++) cout << cnt[i] << endl;

  return 0;
}