#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll N, M;
ll A[100010];
ll ASUM[100010];
ll dp[100010];
unordered_map<ll,ll> map;

int main() {
   ll count=0;
   cin >> N >> M;
   for (ll i=1;i<=N;i++) {
      cin >> A[i];
      ASUM[i] = A[i] + ASUM[i-1];
      map[ASUM[i] % M] = map[ASUM[i] % M] + 1;
      if (ASUM[i] % M == 0) {
	 count++;
      }
   }
   for (auto iter=map.begin(); iter != map.end(); ++iter) {
      ll val = iter->second;
      count += val * (val - 1) / 2;
   }
   cout << count << endl;
   return 0;

}