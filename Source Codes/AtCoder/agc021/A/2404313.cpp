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

  ll n;
  cin >> n;

  ll m = n;
  int k = 0;
  while(m != 0){
    m /= 10;
    ++k;
  }

  int b[k];
  for(int i = 0; i < k; i++){
    for(int j = 9; j >= 0; j--){
      b[i] = j;
      ll sum = 0;
      for(int l = i; l >= 0; l--){
        sum = sum * 10 + b[l];
      }
      if(sum <= n) break;
    }
  }

  int ans = 0;
  for(int i = 0; i < k; i++){
    ans += b[i];
  }

  cout << ans << endl;

  return 0;
}