#include<iostream>
using namespace std;
#include<algorithm>
#include<cmath>
#include<vector>
char a[60];
char b[60];
long long mod=1000000007;
int main()
{
	int n,i,j;
	long long sum;
	while(cin>>n)
	{
		vector<int>c;
		scanf("%s %s",a,b);
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
				c.push_back(1);
			else
			{
				c.push_back(2);
				++i;
			}
		}
		if(c[0]==1)
			sum=3;
		if(c[0]==2)
			sum=6;
		for(i=1;i<c.size();i++)
		{
			if(c[i-1]==1)
				sum*=2;
			else if(c[i-1]==2&&c[i]==1)
				sum*=1;
			else if(c[i-1]==2&&c[i]==2)
				sum*=3;
		}
		sum=sum%mod;
		printf("%lld\n",sum);
	}
	return 0;
}