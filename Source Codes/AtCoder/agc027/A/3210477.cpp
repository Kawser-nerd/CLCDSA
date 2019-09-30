#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  int n, x;
  cin >> n >> x;
  ll a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  ll sum = accumulate(a, a+n, 0ll);
  
  int ans;
  if(x > sum){
    ans = n-1;
  }else if(x == sum){
    ans = n;
  }else{
    sort(a, a+n);
    for(ans = 0;;ans++){
      if(a[ans] > x) break;
      x -= a[ans];
    }
  }
  printf("%d\n",ans);
  return 0;
}