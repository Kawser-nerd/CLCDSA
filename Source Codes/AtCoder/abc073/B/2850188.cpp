#include <iostream>

using namespace std;

int main()
{
  int n; cin >> n;
  int sum;

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    sum += (r - l) + 1;
  }

  cout << sum << endl;

  return 0;
}