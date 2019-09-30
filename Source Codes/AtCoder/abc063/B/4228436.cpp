#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
int main(){
  string s;cin>>s;
  bool ok=true;
  sort(s.begin(),s.end());
  for(int i=0;i<s.size();++i){
    if(i==0)continue;
    if(s[i-1]==s[i])ok=false;  
  }
  if(ok)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}