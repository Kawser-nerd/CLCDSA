// Last Change:    12/16/2018 14:11:58.
#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, L;
  multiset<string> S;
  cin >> N >> L;
  string input;
  for (int i = 0; i < N; i++) {
    cin >> input;
    S.insert(input);
  }
  for (auto itr = S.begin(); itr != S.end(); ++itr) {
    cout << *itr;
  }
  cout << endl;
}