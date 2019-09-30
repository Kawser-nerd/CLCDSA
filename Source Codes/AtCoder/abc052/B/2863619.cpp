#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  int n; cin >> n;
  int x = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    char s; cin >> s;
    if (s == 'I') x += 1;
    else          x -= 1;
    res = max(x, res);
  }

  cout << res << endl;
  return 0;
}