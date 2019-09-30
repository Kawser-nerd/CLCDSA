#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int count = 0;
  for (auto i = 1; i <= n; i += 2) {
    int divisor = 0;
    for (auto j = 1; j <= i; j++) {
      if (i % j == 0) divisor++;
    }
    if (divisor == 8) count++;
  }
  cout << count << endl;
}