#include <iostream> 
using namespace std;int ans,temp;int main(){string s;cin>>s;for(auto c: s){if(c=='A'||c=='T'||c=='G'||c=='C')ans=max(ans,++temp);else temp=0;}cout<<ans;}