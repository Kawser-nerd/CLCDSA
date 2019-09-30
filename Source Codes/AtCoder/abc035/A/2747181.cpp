#include <iostream>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  int w, h;
  cin >> w >> h;
  if ((w % 16) == 0 && (h % 9)  == 0)
    cout << "16:9" << endl;
  else
    cout << "4:3" << endl;
}