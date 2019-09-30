#include <iostream>

using namespace std;

int main()
{
  int n, a, b; cin >> n >> a >> b;
  int sum = 0;

  for (int i = a; i <= n; i++) {
    int x = 0;
    int target = i;
    while(target) {
      x += target % 10;
      target /= 10;
    }
    if (x >= a && x <= b) sum += i;
  }

  cout << sum << endl;

  return 0;
}