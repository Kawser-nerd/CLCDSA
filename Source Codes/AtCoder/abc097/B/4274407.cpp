#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int num[400],s=0,q,ok=0,ans=0;
  for(int i=1;i<=33;i++){
    for(int j=2;j<11;j++){
      num[s]=pow(i,j);
      s++;
    }
  }
  sort(num,num+400);
  cin>>q;
  for(int k=0;k<400;k++){
    if(num[k]>q){
      ans=num[k-1];
      ok++;
      break;
    }
  }
  if(ok==1)
    cout<<ans<<endl;
  else
    cout<<1<<endl;
}