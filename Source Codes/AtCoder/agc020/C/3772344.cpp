#include<bitset>
#include<iostream>
using namespace std;
int a[2009];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int sum=0;
  for(int i=1;i<=n;++i){cin>>a[i];sum+=a[i];}
  //now do that bitset  thing
  bitset<4000004>dp={};
  dp.reset();
  dp[0]=1;
    //for(int i=0;i<=sum;++i)cout<<dp[i]<<" &&\n";
  for(int i=1;i<=n;++i){
    dp=dp|(dp<<a[i]);
    // for(int j=sum;j>=a[i];--j){
    //   if(dp[j-a[i]]==1)dp[j]=1;
    // }
  }
  //now find the smallest one greater than sum/2
//  for(int i=0;i<=sum;++i)cout<<dp[i]<<" **\n";
  for(int j=(sum+1)/2;j<=sum;++j)if(dp[j]==1){cout<<j<<"\n";return 0;}
  return 0;
}