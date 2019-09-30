#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n],z[n];
  for(int i=0;i<n;i++)  cin >> a[i];
  z[n-1] = a[n-1]==0 ? 1 : 0;
  for(int i=n-2;i>=0;i--) z[i] = (a[i]==0? 1 + z[i+1] : 0);
  long long int ans = n;
  for(int i=0;i<n;i++){
    int xr = a[i], sum = a[i];
    int k=0;
  	for(int j=1;i+j+k<n&&xr>=sum/*&&j<=100*/; j++){
      if(a[i+j+k] == 0){
        if(xr==sum){
          ans = ans + z[i+j+k];
        }
        k += z[i+j+k]-1;
      }else{
      	xr ^= a[i+j+k];
      	sum += a[i+j+k];
      	if(xr == sum) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}