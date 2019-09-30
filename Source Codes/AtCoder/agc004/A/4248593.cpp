#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long int 
int main(){
  ll a,b,c,ans;
  cin >> a >> b >> c;
  if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0) ans = 0;
  else{
    ans = min(a * b, b * c);
    ans = min(ans , a * c);
  }
  cout << ans << endl;
  return 0;
}