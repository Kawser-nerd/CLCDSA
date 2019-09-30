#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int64_t n, x;
  cin >> n >> x;
  vector<int64_t> v;
  for (auto i = 0; i < n; i++) {
    int64_t a;
    cin >> a;
    v.push_back(a);
  }
  sort(begin(v), end(v));
  int64_t child = 0;
  for (auto i = 0; i < n; i++) {
    if (v[i] == x) {
      child++;
      x = 0;
      break;
    }
    if (v[i] < x) {
      child++;
      x -= v[i];
    } else {
      child++;
      break;
    }
  }
  if (child != 0 && x != 0) child--;
  cout << child << endl;
  return 0;
}