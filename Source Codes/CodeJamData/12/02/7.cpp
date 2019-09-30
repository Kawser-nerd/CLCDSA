#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

#include "Integer.h"
#include "Rational.h"

using namespace std;


int bestSurprising(int total) {
  if (total <= 2) return total;
  int k = (total-2)/3;
  return k+2;
}

int bestUnsurprising(int total) {
  if (total <= 1) return total;
  int k = (total-1)/3;
  return k+1;
}

int main(void) {
  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    cout << "Case #" << iTest << ": ";

    int i, n, surprises, p;
    cin >> n >> surprises >> p;

    int total;
    int nGood = 0, nGoodOnlyIfSurprising = 0;
    for (i = 0; i < n; ++i) {
      cin >> total;
      if (bestUnsurprising(total) >= p)
	++nGood;
      else if (bestSurprising(total) >= p)
	++nGoodOnlyIfSurprising;
    }

    if (nGoodOnlyIfSurprising > surprises) nGoodOnlyIfSurprising = surprises;

    cout << nGood + nGoodOnlyIfSurprising;
    

    cout << "\n";
  }

  return 0;
}
