#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  double a,b,c,d,ans;
  cin>>a>>b;
  d=b*6;
  if(a>12)
    c=(a-12)*30+b/2;
  else{
    c=a*30+b/2;
  }
  ans=abs(d-c);
  if(ans>180)
    cout<<abs(ans-360)<<endl;
  else
    cout<<ans<<endl;
}