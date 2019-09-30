#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
  int n;
  scanf("%i", &n);
  
  int m = 3 * n;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    scanf("%i", &a[i]);
  }
  
  long long sum = 0;
  priority_queue<int> pq;
  vector<long long> dp(m);
  for (int i = 0; i < n; i++) {
    pq.push(-a[i]);
    sum += a[i];
  }
  
  dp[n-1] = sum;
  for (int i = n; i < m; i++) {
    if (-pq.top() <= a[i]) {
      sum += a[i] + pq.top();
      pq.pop();
      pq.push(-a[i]);
    }
    dp[i] = sum;
  }
  
  sum = 0;
  while (!pq.empty()) {
    pq.pop();
  }
  
  for (int i = m-n; i < m; i++) {
    pq.push(a[i]);
    sum += a[i];
  }
  
  long long ans = dp[m-n-1] - sum;
  for (int i = m-n-1; i >= n; i--) {
    if (pq.top() >= a[i]) {
      sum += a[i] - pq.top();
      pq.pop();
      pq.push(a[i]);
    }
    ans = max(ans, dp[i-1] - sum);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}