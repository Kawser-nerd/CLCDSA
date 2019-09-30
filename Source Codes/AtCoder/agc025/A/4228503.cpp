#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
int ketawa(int a){
  int wa=0;
  while(a!=0){
    wa += a%10;
    a /= 10;  
  }
  return wa;
}
int main(){
  int n; cin>>n;
  int ans = n;
  for(int i=1;i<n;++i){
    int temp = ketawa(i) + ketawa(n-i);
    ans  = min(ans,temp);
  }
  cout<<ans<<endl;
}