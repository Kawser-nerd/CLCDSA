#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  for (auto i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int max_swing = *max_element(begin(a), end(a));
  sort(begin(b), end(b), greater<>());
  int count = 0;
  for (auto&& e : b) {
    if (e > max_swing) {
      count++;
      h -= e;
      if (h <= 0) break;
    }
  }
  if (h > 0) {
    count += h / max_swing;
    if (h % max_swing != 0) count++;
  }
  cout << count << endl;
}