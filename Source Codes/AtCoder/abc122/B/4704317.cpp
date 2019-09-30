#include <iostream>
using namespace std;
int main(){
  int ans=0,temp=0;
  string s;
  cin>>s;
  for(auto c: s) {
    if(c=='A'||c=='T'||c=='G'||c=='C')ans=max(ans,++temp);  
    else temp=0;
  }
  cout<<ans<<endl;
  return 0;
}