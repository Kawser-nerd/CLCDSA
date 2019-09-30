#include<iostream>
#include<algorithm>

using namespace std;
#define MOD 1000000007
typedef long long Int;

Int calc(Int *x, Int n){
  Int res = 0;
  for(int i = 0;i < n-1;i++){
    res += (x[i+1] - x[i]) * (i+1) %MOD * (n - i - 1) %MOD;
    res %= MOD;
  }
  return res;
}


Int x[108000], y[108000], n, m;
int main(){
  cin >> n >> m;
  for(int i = 0;i < n;i++) cin >> x[i];
  for(int i = 0;i < m;i++) cin >> y[i];

  cout << calc(x, n) * calc(y, m) % MOD << endl;
  return 0;  
}