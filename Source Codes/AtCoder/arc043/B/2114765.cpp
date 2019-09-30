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
#define DEBUG true
//#define DEBUG false
#define MOD (1000000007)
using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int d[n];
  for(int i = 0; i < n; i++){
    cin >> d[i];
  }

  sort(d, d + n);
  ll s[4][n + 1];
  for(int i = 0; i < 4; i++){
    s[i][n] = 0;
  }
  for(int i = n - 1; i >= 0; i--){
    s[0][i] = s[0][i + 1] + 1;
  }
  for(int i = 1; i < 4; i++){
    for(int j = n - 1; j >= 0; j--){
      int m = distance(d, lower_bound(d, d + n, 2 * d[j]));
      s[i][j] = (s[i - 1][m] + s[i][j + 1]) % MOD;
    }
  }

  cout << s[3][0] << endl;

  return 0;
}