#include <iostream>
using namespace std;

int64_t sheets[50] {1};
int64_t patties[50] {1};

int64_t f(int64_t n, int64_t x)
{
  if (x <= 0) return 0;
  if (n <= 0) return 1;
  if (x <= sheets[n - 1] + 1) {
    return f(n - 1, x - 1);
  } else {
    return patties[n - 1] + 1 + f(n - 1, x - 2 - sheets[n - 1]);
  }
}

int main()
{
  int64_t n, x;
  cin >> n >> x;
  for (auto i = 1; i < n; i++) {
    sheets[i] = sheets[i - 1] * 2 + 3;
    patties[i] = patties[i - 1] * 2 + 1;
  }
  cout << f(n, x) << endl;
}