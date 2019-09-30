#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))


int main(void)
{
	//?????
	int n;
	llong m=0;
	llong a[50];
	llong b[50];
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	llong int max,min;
	int len;
	llong int sum=0;
	//????????
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<n;i++){
		if(i==0)min=a[0];
		min = min(min,a[i]);
	}
	
//	printf("min=%d\n",min);
	
	for(i=0;i<n;i++){
		b[i]=(a[i]-min)/(n+1);
		m=m+b[i];
//		printf("b[%d]=%d\n",i,b[i]);
	}
	
	for(i=0;i<n;i++){
//		printf("a[i]=%lld,b[i]=%lld,n=%d,m=%lld,ans=%lld\n",a[i],b[i],n,m,a[i]-b[i]*n+(m-b[i]));
		a[i]=a[i]-b[i]*n+(m-b[i]);
	}
	
/*	for(i=0;i<n;i++){
		printf("%lld ",a[i]);
	}
	printf("\n");
	
	for(i=0;i<n;i++){
		printf("%lld ",b[i]);
	}
*/	
	for(i=0;i<n;i++){
		if(i==0) max=a[0];
		max=max(max,a[i]);
	}
	
	if(max>n+50){
		for(i=0;i<n;i++){
			a[i]=a[i]-(max-n-50);
		}
		m=m+(max-n-50)*n;
	}
	
	flag=1;
	while(flag==1){
		count++;
	//	printf("count=%d ",count);
	//	for(i=0;i<n;i++){
	//		printf("%lld ",a[i]);
	//	}
	//	printf("\n");

		flag=0;
		for(i=0;i<n;i++){
			if(flag==0&&a[i]>=n){
				a[i]=a[i]-n-1;
				flag=1;
			}
		}
		if(flag==1){
			for(i=0;i<n;i++){
				a[i]++;
			}
			m++;
		}
	}
	
//	printf("??????\n");
	//??
	
	printf("%lld",m);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^