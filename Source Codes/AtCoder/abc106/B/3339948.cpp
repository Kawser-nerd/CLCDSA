#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=105;i<=n;i+=2)
	{
		int t=0;
		for(int j=1;j<=i;j++) if(i%j==0) t++;
		if(t==8) ans++;	
	}	
	cout<<ans<<endl;
	return 0;
}