#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t[101];

int main()
{
  int n, m;
  int sumInit;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    sumInit += t[i];
  }

  cin >> m;
  int ans[m];

  for (int i = 1; i <= m; i++) {
    int x, p, sum;
    cin >> x >> p;
    sum = sumInit + p - t[x];
    ans[i] = sum;
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}