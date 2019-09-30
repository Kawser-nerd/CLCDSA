#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n,ans,count=0,sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>ans;
    sum+=ans;
    if(ans>count){
      count=ans;
    }
  }
  if(count<sum-count){
    cout<<"Yes"<<endl;
  }
  else
    cout<<"No"<<endl;
}