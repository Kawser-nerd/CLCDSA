#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, ans;
  cin >> n;
  int h[n];
  for(int i=0;i<n;++i) cin >> h[i];

  //operation
  ans = h[0];
  for(int i=1;i<n;++i){
    if(h[i-1] <= h[i])
      ans += h[i]-h[i-1];
  }

  cout << ans << endl;

  return 0;
}