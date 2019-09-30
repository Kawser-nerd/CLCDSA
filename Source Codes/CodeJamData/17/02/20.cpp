#include <iostream>
#include <vector>
#include <string>
using namespace std;

string n;


int main() {
  int numCases;
  cin >> numCases;
  for (int testCase=1; testCase<=numCases; ++testCase) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    int plateau=0;
    bool tidy = true;
    for (int i=1; i<n.size(); ++i) {
      if (n[i] > n[i-1])
        plateau = i;
      else if (n[i] < n[i-1]) {
        tidy = false;
        break;
      }
    }
    if (!tidy) {
      n[plateau]--;
      for (int i=plateau+1; i<n.size(); ++i)
        n[i]='9';
      if (n[0] == '0')
        n = n.substr(1);
    }
    cout << n << endl;
  }
}