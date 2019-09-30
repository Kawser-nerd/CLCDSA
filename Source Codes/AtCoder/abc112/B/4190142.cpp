#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int n,t,count=10000,cc,ans=0;
  int cost[2000];
  int num[2000];
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>cost[i]>>num[i];
  }
  for(int j=0;j<n;j++){
    if(num[j]<=t){
      ans++;
      cc=min(cost[j],count);
      if(cost[j]<count)
        count=cost[j];
    }
  }
  if(ans==0)
    cout<<"TLE"<<endl;
  else
    cout<<cc<<endl;
}