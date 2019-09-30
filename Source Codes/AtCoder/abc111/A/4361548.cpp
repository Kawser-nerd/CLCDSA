#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans{};

  for (int i{1}; n > 0; i *= 10) {
    int d{n % 10 == 9 ? 1 : 9};
    ans += d * i;
    n /= 10;
  }

  cout << ans << endl;
}