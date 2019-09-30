#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
  int n;
  cin >> n;
  vec<int> h(n);
  rep(i, n) cin >> h[i];

  int count = 0;
  rep(i, 100) {
    int prev = 0;
    rep(j, n) {
      if (h[j] == 100 - i) {
        h[j]--;
        if (!prev) {
          prev = 1;
          count++;
        }
      } else {
        prev = 0;
      }
    }
  }
  cout << count << endl;
  return 0;
}