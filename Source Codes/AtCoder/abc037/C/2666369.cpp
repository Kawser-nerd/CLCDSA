#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int N, K;

  cin >> N >> K;

  vector< long long int > a(N);
  for(int i = 0; i < N; i++) cin >> a[i];

  vector< long long int > sum;
  long long int tmp = 0;
  for(int i = 0; i < K; i++) {
    tmp += a[i];
  }
  sum.push_back(tmp);
  for(int i = 1; i <= N - K; i++) {
    sum.push_back(sum.back() - a[i-1] + a[i+K-1]);
  }

  long long int ans = 0;
  for(auto s : sum) ans += s;
  cout << ans << endl;
}