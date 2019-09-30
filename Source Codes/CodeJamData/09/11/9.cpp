#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

bool happyCache[1000][11];

int next(int num, int base) {
  int r = 0;
  while (num) {
    r += (num % base)*(num % base);
    num /= base;
    }
  return r;
  }

bool happy(int num, int base) {
  set<int> seen;
  while ((num > 1) && !seen.count(num)) {
    seen.insert(num);
    num = next(num, base);
    }
  return (num == 1);
  }

bool happyCheck(int num, int base) {
  if (num < 1000) return happyCache[num][base];
  else return happyCheck(next(num, base), base);
  }

bool happyB(int a, vector<int> &bases) {
  for (vector<int>::reverse_iterator i = bases.rbegin(); i != bases.rend(); ++i)
    if (!happyCheck(a, *i)) return false;
  return true;
  }

int main() {
  for (int i = 1; i < 1000; ++i)
    for (int b = 2; b <= 10; ++b)
      happyCache[i][b] = happy(i, b);
  int T; cin >> T; cin.ignore();
  for (int cc = 1; cc <= T; ++cc) {
    string line; getline(cin, line);
    stringstream ss(line);
    int t; vector<int> bases;
    while (ss >> t) bases.push_back(t);
    sort(bases.begin(), bases.end());
    int a = 2;
    while (!happyB(a, bases)) ++a;
    cout << "Case #" << cc << ": " << a << "\n";
    }
  }