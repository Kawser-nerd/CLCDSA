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

ll ceil(ll x, ll y){
  return (x + y - 1) / y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  ll a[n], b[n];
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }

  ll k = 0;
  for(int i = n - 1; i >= 0; i--){
    k += ceil((a[i] + k), b[i]) * b[i] - (a[i] + k);
  }

  cout << k << endl;

  return 0;
}