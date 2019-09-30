#include<iostream>
using namespace std;
#include<algorithm>
#include<cmath>
#define N 100010
long long a[N];
int main()
{
	int n,i,k,j;
	long long tempa,tempb;
	while(cin>>n){
		tempa=0;
		tempb=0;
		k=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(i=n-1;i>=1;i--)
			if(a[i]==a[i-1])
			{
				tempa=a[i];
				k=i-1;
				break;
			}
		for(j=k-1;j>=1;j--)
			if(a[j]==a[j-1])
			{
				tempb=a[j];
				break;
			}
			printf("%lld\n",tempa*tempb);
	}
	return 0;
}