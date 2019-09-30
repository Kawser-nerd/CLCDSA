#include<string>
#include<iostream>
using namespace std;
int n;
long long x[100001],a,b;
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	  cin>>x[i];
	long long ans=0;
	for(int i=2;i<=n;i++)
	  if((x[i]-x[i-1])*a>b) ans+=b;
	  else ans+=(x[i]-x[i-1])*a;
	cout<<ans;
}