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
  int ans = ketawa(n);
  if(ans==1)ans=10;
  cout<<ans<<endl;
}