#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  ll A, B, C;
  cin >> A >> B >> C;
  if (A + B >= C - 1)
    cout << B + C << endl;
  else {
    cout << B + B + A + 1 << endl;
  }
  return 0;
}