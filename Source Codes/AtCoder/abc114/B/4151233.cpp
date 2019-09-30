#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  string s;
  cin>>s;
  int m,ans,x,y,count=10000;
  for(int i=0;i<s.size()-2;i++){
    x=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
    y=abs(753-x);
    if(y<count){
      ans=y;
      count=y;
    }
  }
  cout<<ans<<endl;
}