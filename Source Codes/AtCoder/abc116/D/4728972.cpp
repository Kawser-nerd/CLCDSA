#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define ll long long

int main(void)
{
  int n, k;
  cin >> n >> k;
  vec<pair<ll, ll>> s(n);
  rep(i, n) cin >> s[i].second >> s[i].first;
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());

  ll m = 0;
  vec<ll> dp(n + 1, 0);
  ll p = 0;
  rep(i, k) {
    m += s[i].first;
    if (!dp[s[i].second]) p++;
    dp[s[i].second]++;
  }

  m += p * p;
  ll prev = m;
  //????????????????
  int cur = k;
  //????????????????????
  int rm = k - 1;

  for (int i = 1; p + i <= k; i++) {
    ll p_ = p + (ll)i;
    //???????????
    while(rm >= 0 && dp[s[rm].second] <= 1) rm--;
    if (rm < 0) break;
    ll temp = prev - s[rm].first + 2 * p_ - 1;
    dp[s[rm].second]--;
    rm--;
    //?????????????
    while(cur < n && dp[s[cur].second]) cur++;
    if (cur >= n) break;
    temp += s[cur].first;
    dp[s[cur].second]++;
    cur++;

    if (temp > m) {
      m = temp;
    }
    prev = temp;
  }

 cout << m << endl;
  return 0;
}