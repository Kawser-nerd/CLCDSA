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

const int MAX = 100001;
const int MOD = 1000000007;

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

  ll a, b;
  cin >> a >> b;


  ll ans = 0;
  --a;
  for(int i = 1; i < 64; i++){
    ll ca = (1l << (i - 1)) * ((a + 1) / (1l << i));
    ll r = (a + 1) % (1l << i);
    if(r > (1l << (i - 1))) ca += r - (1l << (i - 1));

    ll cb = (1l << (i - 1)) * ((b + 1) / (1l << i));
    r = (b + 1) % (1l << i);
    if(r > (1l << (i - 1))) cb += r - (1l << (i - 1));

    if((cb - ca) % 2 == 1) ans |= (1l << (i - 1));
  }

  cout << ans << endl;

  return 0;
}