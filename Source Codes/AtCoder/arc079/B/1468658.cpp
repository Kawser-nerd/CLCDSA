#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int e=10000000000000000;
int k,n,a[100];
signed main()
{
	scanf("%lld",&k);
	n=k/e+bool(k%e);
	if(n<3)n=2;
	for(int i=1;i<=n;i++)a[i]=n-1;
	int tot=0;
	while(tot<k)
	{
		sort(a+1,a+1+n);
		int buf=-1;
		for(int i=1;i<=n;i++)
			if(a[i]==a[1])buf++;
			else break;
		
		buf=a[1]-buf+1;
		if(a[1]+buf*n>e+1000)buf-=(a[1]+buf*n-e-1000)/n;
		while(a[1]+buf*n>e+1000)buf--;
		if(tot+buf>k)buf=k-tot;
		a[1]+=buf*n;
		for(int i=2;i<=n;i++)a[i]-=buf;
		tot+=buf;
	}
	printf("%lld\n",n);
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	puts("");
	return 0;
}