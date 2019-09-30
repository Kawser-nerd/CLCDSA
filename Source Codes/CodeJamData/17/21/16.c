#include <stdio.h>

int main(void) {
	freopen("A-large.in","r",stdin);
    freopen("A-largeoutput.out","w",stdout);
	long long int t,d,n,k,s,i,j;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
	    scanf("%lld %lld",&d,&n);
	    double x1,x2,x3,val,ti,ans;
	    long long int a[n][2];
	    for(j=0;j<n;j++)
	    scanf("%lld %lld",&a[j][0],&a[j][1]);
	    x1=d;
	    x2=a[0][0];
	    x3=a[0][1];
	    ti=(x1-x2)/x3;
	    for(j=1;j<n;j++)
	    {
	        x2=a[j][0];
	        x3=a[j][1];
	        val=(x1-x2)/x3;
	        if(val>ti)
	        ti=val;
	    }
	    ans=d/ti;
	    printf("Case #%lld: %lf\n",i,ans);
	}
	return 0;
}

