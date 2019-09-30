#include <iostream>

using namespace std;

int nums[200001];
int back[20];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }

  for (int i = 0; i < 20; i++) {
    back[i] = 0;
  }

  long long res = 0;
  int sum = 0;
  for (int f = 0; f < 20; f++) {
    if ((1 << f) & nums[1]) {
      back[f] = 1;
    }
  }
  sum += nums[1];
  res += 1;

  int b = 1;
  for (int i = 2; i <= n; i++) {
    if (sum & nums[i]) {
      for (int f = 0; f < 20; f++) {
        if (((1 << f) & nums[i]) && b < back[f] + 1) {
          b = back[f] + 1;
        }
      }
      for (int f = 0; f < 20; f++) {
        if (b > back[f] && (sum & (1 << f))) {
          back[f] = 0;
          sum -= (1 << f);
        }
      }
    }
    for (int f = 0; f < 20; f++) {
      if ((1 << f) & nums[i]) {
        back[f] = i;
      }
    }
    sum += nums[i];
    res += i - b + 1;
  }
  cout << res << endl;
}