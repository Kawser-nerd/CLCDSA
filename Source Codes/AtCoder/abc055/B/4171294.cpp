#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;
int main(){
  long n,ans=1;
  cin>>n;
  for(int i=1;i<=n;i++){
    ans*=i;
    ans=ans%1000000007;
  }
  cout<<ans<<endl;
}