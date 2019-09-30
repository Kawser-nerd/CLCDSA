#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int n,ans,time=10000;
  cin>>n;
  int x[110];
  for(int i=0;i<n;i++){
    cin>>x[i];
    ans=min(x[i],time);
    if(x[i]<=time)
      time=x[i];
  }
  cout<<ans<<endl;
}