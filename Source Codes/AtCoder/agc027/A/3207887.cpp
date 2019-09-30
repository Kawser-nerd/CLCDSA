#include <iostream>
#include <vector>

using namespace std;

int main()
{
  uint64_t n, x;
  cin >> n >> x;
  vector<uint64_t> v;
  for (auto i = 0; i < n; i++) {
    uint64_t a;
    cin >> a;
    v.push_back(a);
  }
  sort(begin(v), end(v));
  uint64_t child = 0;
  for (auto i = 0; i < n; i++) {
    child++;
    if (v[i] <= x) {
      x -= v[i];
      if (x == 0) break;
    } else {
      break;
    }
  }
  if (x > 0 && child > 0) child--;
  cout << child << endl;
  return 0;
}