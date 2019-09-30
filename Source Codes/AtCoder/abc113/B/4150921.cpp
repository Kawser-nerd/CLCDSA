#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  double x[2000];
  double n,t,a,ans,tem=33333;
  cin>>n;
  cin>>t>>a;
  for(int i=0;i<n;i++){
    cin>>x[i];
    x[i]=t-x[i]*0.006;
  }
  for(int j=0;j<n;j++){
    double aa=abs(a-x[j]);
    if(aa<tem){
      ans=j+1;
      tem=aa;
    }
  }
  cout<<ans<<endl;
}