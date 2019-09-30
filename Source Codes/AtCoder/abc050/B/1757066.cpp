#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const* argv[])
{
  int n, ts[100], m, p, x;

  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> ts[i];
    sum += ts[i];
  }
  cin >> m;

  while (m--) {
    cin >> p >> x;
    cout << sum - ts[p-1] + x << endl;
  }

  return 0;
}