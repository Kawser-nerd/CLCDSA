#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int n,x=0,ans,bb=0;
  string aa;
  cin>>n>>aa;
  for(int i=0;i<n;i++){
    if(aa[i]=='D')
      x--;
    else{
      x++;
    }
    ans=max(x,bb);
    if(x>bb)
      bb=x;
  }
  cout<<ans<<endl;
}