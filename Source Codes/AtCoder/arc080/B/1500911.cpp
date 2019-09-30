#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void print_front(vector<int>& line) {
  bool first = true;
  for (int i = 0; i < line.size(); i++) {
    if (!first) {
      cout << " ";
    }
    cout << line[i];
    first = false;
  }
  cout << endl;
}

void print_back(vector<int>& line) {
  bool first = true;
  for (int i = line.size() - 1; i >= 0; i--) {
    if (!first) {
      cout << " ";
    }
    cout << line[i];
    first = false;
  }
  cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w, n;
  cin >> h >> w >> n;

  vector<int> a(n);

  for (auto& e : a) {
    cin >> e;
  }

  vector<int> line;
  bool odd = true;

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i]; j++) {
      line.push_back(i+1);
      if (line.size() == w) {
        if (odd) {
          print_front(line);
        } else {
          print_back(line);
        }
        line.clear();
        odd = !odd;
      }
    }
  }
  return 0;
}