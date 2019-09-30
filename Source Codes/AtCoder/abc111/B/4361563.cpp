#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans{111};

  for (int i{1}; i <= 9; ++i) {
    if (n <= ans * i) {
      ans *= i;
      break;
    }
  }

  cout << ans << endl;
}