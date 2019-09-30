#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
// Compare vec[key] and something.
bool BinarySearch_Comp(const int key, const std::vector<int64_t>& vec) {
  // cerr << "\033[93m"
  //      << "======="
  //      << "\033[m" << endl;
  int64_t target = vec[key];
  // cerr << "\033[93m" << target << "\033[m" << endl;
  for (int i = 0; i < key; i++) {
    target += vec[i];
  }
  // cerr << "\033[93m" << target << "\033[m" << endl;
  for (int i = key + 1; i < vec.size(); i++) {
    if (vec[i] <= target * 2) {
      target += vec[i];
      // cerr << "\033[93m"
      //      << "eat " << i << " size: " << target << "\033[m" << endl;
    } else {
      // cerr << "\033[93m"
      //      << "can't  eat"
      //      << "\033[m" << endl;
      return false;
    }
  }
  return true;
}

// Return index number whose element is the LOWER limit returning true in
// BS_Comp().
int BinarySearch_LowerLimit(const std::vector<int64_t>& vec) {
  int left  = -1;
  int right = vec.size();
  int mid;
  while (right - left > 1) {
    mid = left + (right - left) / 2;
    if (BinarySearch_Comp(mid, vec)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}

void OutputError(std::string s) {
  cerr << "\033[93m" << s << "\033[m" << endl;
  return;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  std::vector<int64_t> a;
  for (int i = 0; i < n; i++) {
    int m1;
    cin >> m1;
    a.push_back(m1);
  }
  std::sort(a.begin(), a.end());
  int limit = BinarySearch_LowerLimit(a);
  cout << n - limit << endl;

  return 0;
}