#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  vector<int> a(N);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  vector<int> a_continuity;
  for (size_t i = 1; i < a.size(); i++) {
    if (a[i - 1] == a[i]) {
      if (a_continuity.empty()) {
        a_continuity.push_back(2);
      } else {
        a_continuity.back()++;
      }
    } else {
      a_continuity.push_back(1);
    }
    //cout << "debug;" << a_continuity[i] << endl;
  }
  int ans = 0;
  for (size_t i = 0; i < a_continuity.size(); i++) {
    ans += a_continuity[i] / 2;
    // cout << a_continuity[i] << endl;
  }
  cout << ans << endl;
  return 0;
}