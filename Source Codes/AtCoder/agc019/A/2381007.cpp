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
using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll q, h, s, d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;

  ll one = min(q * 4, min(h * 2, s));
  ll two = min(one * 2, d);

  ll ans;
  if(n % 2 == 0){
    ans = (n / 2) * two;
  }
  else{
    ans = (n / 2) * two + one;
  }

  cout << ans << endl;

  return 0;
}