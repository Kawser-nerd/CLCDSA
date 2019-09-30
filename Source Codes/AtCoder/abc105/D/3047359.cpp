#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MAX_N 100000
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, int > pli;

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  pli sum[MAX_N];
  sum[0] = make_pair(a[0] % m, 0);
  for(int i = 1; i < n; i++){
    sum[i] = make_pair(
        (sum[i - 1].first + a[i]) % m, i);
  }

  sort(sum, sum + n);

  ll ans = 0;
  ll s = 0;
  for(int i = 0; i < n; i++){
    ans += distance(lower_bound(
          sum, sum + n, make_pair(s, i)),
        upper_bound(sum, sum + n, 
          make_pair(s, n - 1)));
    s = (s + a[i]) % m;
  }

  cout << ans << endl;

  return 0;
}