#include <iostream>

using namespace std;

int main()
{
  int n; cin >> n;

  int a_max = 0;
  int a_min = 1000;

  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    if (a_max < a) a_max = a;
    if (a_min > a) a_min = a;
  }

  cout << a_max - a_min << endl;

  return 0;
}