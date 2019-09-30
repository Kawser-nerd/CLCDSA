#include <iostream>

using namespace std;

int main()
{
  int a, b;
  int res;

  cin >> a >> b;

  for (int i = a; i <= b; i++) {
    int target = i;
    int x5 = target % 10;

    target /= 10;

    int x4 = target % 10;

    target /= 100;

    int x1 = target % 10;

    int x0 = target / 10;

    if (x0 == x5 && x1 == x4) res++;
  }

  cout << res << endl;

  return 0;
}