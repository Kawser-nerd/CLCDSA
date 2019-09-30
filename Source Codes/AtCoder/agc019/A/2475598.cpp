#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main(){
  ll a,b,c,d,n;
  cin >> a >> b >> c >> d;
cin >> n;
  if(d == min({a*8,b*4,c*2,d})){
    if(n%2==1){
      cout << (n/2)*d + min({a*4,b*2,c});
    }else{
      cout << (n/2)*d << endl;
    }
  }else{
    int mi = min({a*4,b*2,c});
    cout << n*mi << endl;
  }
  return 0;
}