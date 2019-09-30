// Last Change: 02/18/2019 23:39:56.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

void Output(ll data) {
  if (data < 10) {
    cout << 0;
  }
  cout << data;
}

void Ans(ll hh, ll mm, ll ss) {
  Output(hh);
  cout << ":";
  Output(mm);
  cout << ":";
  Output(ss);
  cout << endl;
}

int main() {
  ll N;
  cin >> N;

  ll hh, mm, ss;
  hh = N / 3600;
  N = N % 3600;
  mm = N / 60;
  N = N % 60;
  ss = N;

  Ans(hh, mm, ss);

  //NS::LoopUntilZeroInpput();
}