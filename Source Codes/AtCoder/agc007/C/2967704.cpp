#include<iostream>
#include<cstdio>
#define db double
using namespace std;

int n;
db x,d,ans,tmp;

int main()
{
	int i,j;
	cin>>n>>d>>x;
	for(;n;n--)
	{
		ans+=(d*2.0+(db)(2*n-1)*x)/2.0;
		tmp=d;
		d+=d/(db)n+5.0*x/(db)(2*n);
		x+=2.0*x/(db)n;
//		cout<<ans<<" "<<d<<" "<<x<<endl;
	}
	printf("%.10f",ans);
}