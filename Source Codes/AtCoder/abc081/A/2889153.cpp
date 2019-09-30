#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char* argv[]) {
  int n, count;
  count = 0;

  cin >> n;

  count += n / 100;
  n = n % 100;
  count += n / 10;
  n = n % 10;
  count += n / 1;

  cout << count << endl;

  return 0;
}