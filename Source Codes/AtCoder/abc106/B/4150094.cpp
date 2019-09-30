#include<iostream>
using namespace std;
int main(){
  int n,count=0,ans=0;
  cin>>n;
  for(int j=1;j<=n;j++){
    for(int i=1;i<=n;i++){
      if(j%i==0){
        count++;
      }
    }
    if(j%2==1 and count==8){
      ans++;
    }
    count=0;
  }
  cout<<ans<<endl;
}