#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

long long a[38];
long long tot;
int N, n;
double calc(long long y)
{
	//cout<<y<<endl;
	if (y<=0) return 0;
	long long tmp = 0;
	int k = 0;
	for (int i=0;i<37;++i)
		if (a[i]<=y) 
		{
			tmp = tmp+y-a[i];
			k=k+1;
		}
	//cout<<tmp<<' '<<k<<endl;
	double tans = 0;
	if (k==0) return 0;
	long long used = tmp;
	while (used<=tot && k>0)
	{
		tans = max(tans, (tmp+0.)/(k+0.)*36-used);
		++used;;
		--k;
		tmp = tmp - (y-a[k]);
	}
	return tans;
}
int main()
{
	cin>>N;
	for (int I=1;I<=N;++I)
	{
		cin>>tot>>n;
		memset(a, 0, sizeof a);
		for (int i=0;i<n;++i)
			cin>>a[i];
		sort(a, a+37);
		double ans = 0;
		for (int i=0;i<37;++i)
		{
			ans=max(ans, calc(a[i]));
			ans=max(ans, calc(a[i]-1));
		}
		long long sum=0;
		for (int i=0;i<37;++i)
		{
			sum = sum + a[i];
			long long x = (tot+sum)/(i+1);
			if (x<=a[i+1])
			{
				ans = max(ans, calc(x));
				ans = max(ans, calc(x-1));
			}
		}
		cout<<"Case #"<<I<<": "<<setprecision(9)<<fixed<<ans<<endl;
	}
}
