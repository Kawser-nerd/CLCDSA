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

  if(n == 1l){
    cout << "Deficient" << endl;
    return 0;
  }

  ll sum = 1;
  for(ll i = 2; i * i <= n; i++){
    if(i * i == n) sum += i;
    else if(n % i == 0l) sum += i + (n / i);
  }

  if(sum == n) cout << "Perfect" << endl;
  else if(sum < n) cout << "Deficient" << endl;
  else cout << "Abundant" << endl;

  return 0;
}