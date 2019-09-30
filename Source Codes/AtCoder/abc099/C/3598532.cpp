#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100001;
int dp[MAXN];

int rec_bank(int n) {
  int ret = n;
  if (n == 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];

  for (int pow6 = 1; pow6 <= n; pow6 *= 6)
    ret = min(ret, rec_bank(n - pow6) + 1);
  for (int pow9 = 1; pow9 <= n; pow9 *= 9)
    ret = min(ret, rec_bank(n - pow9) + 1);
  return dp[n] = ret;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < MAXN; i++)
    dp[i] = -1;
  cout << rec_bank(N) << endl;
  return 0;
}