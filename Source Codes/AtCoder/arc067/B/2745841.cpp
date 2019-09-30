#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  int n;
  ll a, b, x[SIZE];

  scanf("%d%lld%lld", &n, &a, &b);

  ll ans = 0;
  
  for(int i=0;i<n;i++){
    scanf("%lld", x+i);
    if(i > 0) ans += min((x[i] - x[i-1]) * a, b);
  }

  cout << ans << endl;
  
  return 0;
}