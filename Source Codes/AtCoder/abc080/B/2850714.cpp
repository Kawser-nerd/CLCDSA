#include <iostream>

using namespace std;

int main()
{
  int n; cin >> n;
  int n_init = n;
  int harshad = 0;

  while (n) {
    harshad += n % 10;
    n /= 10;
  }

  if (n_init % harshad == 0) cout << "Yes" << endl;
  else                       cout << "No" << endl;

  return 0;
}