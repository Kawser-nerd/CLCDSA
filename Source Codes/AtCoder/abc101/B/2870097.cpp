#include<iostream>
using namespace std;
const int maxn = 1e6+10;
int m,n;
int main()
{
	cin>>n;
	int j=n;
	long long ans=0;
	while(n)
	{
		ans+=n%10;
		n/=10;
	}
	if(j%ans==0) cout<<"Yes";
	else cout<<"No";
}