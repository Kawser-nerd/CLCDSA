#include <stdio.h>
#include <math.h>
#define int long long

int ketaf(int,int);

signed main(void)
{
	int n,a,b,i,keta,min=11;
	scanf("%lld",&n);
	for(i=1;i*i<=n;i++)
	{
		/* fprintf(stderr,"mai=%d\n",i); */
		if(n%i==0)
			{
			a=i,b=n/i;
			keta=ketaf(a,b);
			if(keta<min){min=keta;}
			}
	/* if(end==1){break;} */
	}
	printf("%lld\n",min);
return 0;
}

int ketaf(int a,int b)
{
	int i=1,ka=1,kb=1;
	while(1)
	{
		/* fprintf(stderr,"kfi=%d",i ); */
		i*=10;
		if(a/i>=1){ka++;}
		if(b/i>=1){kb++;}
		if(a/i==0 && b/i==0){break;}
	}
	if(ka>=kb){return ka;}
	else{return kb;}
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^