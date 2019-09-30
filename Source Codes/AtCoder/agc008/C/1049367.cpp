#include <iostream>
using namespace std;

int main() {
  long int nI, nO, nJ, nL, gomi;
  cin >> nI >> nO >> gomi >> nJ >> nL >> gomi >> gomi;
  int oddnum = nI % 2 + nJ % 2 + nL % 2;
  if (oddnum > 1 && nI * nJ * nL != 0) oddnum = 3 - oddnum;
  cout << nI + nO + nJ + nL - oddnum << endl;
  return 0;
}