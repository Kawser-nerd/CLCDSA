#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  double a, b;
  cin >> a >> b;
  cout << static_cast<int>(ceil(b / a)) << endl;
}