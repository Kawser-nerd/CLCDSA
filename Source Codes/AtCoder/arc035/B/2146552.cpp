#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MOD (1000000007)
using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int time[n];
  for(int i = 0; i < n; i++){
    cin >> time[i];
  }

  sort(time, time + n);
  ll sum = 0;
  ll t = 0;
  for(int i = 0; i < n; i++){
    t += time[i];
    sum = sum + t;
  }

  ll fact[n + 1];
  fact[0] = 1;
  for(int i = 1; i <= n; i++){
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  ll count = 1;
  int s = 0;
  while(s < n){
    int u = s;
    while(u + 1 < n && time[u] == time[u + 1]){
      ++u;
    }
    count = (count * fact[u - s + 1]) % MOD;
    s = u + 1;
  }

  cout << sum << endl;
  cout << count << endl;

  return 0;
}