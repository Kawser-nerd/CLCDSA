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
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

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

  int n;
  cin >> n;
  int p[n];
  for(int i = 0; i < n; i++) cin >> p[i];

  int a[n + 1];
  for(int i = 0; i < n; i++){
    a[p[i]] = i;
  }

  int mx = 1, c = 1;
  for(int i = 1; i + 1 <= n; i++){
    if(a[i] < a[i + 1]) ++c;
    else c = 1;
    mx = max(mx, c);
  }

  int ans = n - mx;

  cout << ans << endl;

  return 0;
}