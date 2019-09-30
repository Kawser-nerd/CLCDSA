#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))




int main(void)
{
	//?????
	int q;
	llong int a[110];
	llong int b[110];
	
	//??????
	int i,j,k,l;
	int flag=0;
	llong int ans=0;
	int count=0;
	int sum=0;
	long int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%d",&q);
	
	for(i=0;i<q;i++){
		scanf("%lld %lld",&a[i],&b[i]);
	}
	
//	for(i=0;i<q;i++){
//		printf("%lld %lld\n",a[i],b[i]);
//	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	for(i=0;i<q;i++){
//		printf("i=%d q=%d\n",i,q);
		if(a[i]==b[i]){
			printf("%lld\n",2*a[i]-2);
		}else if(abs(a[i]-b[i])==1){
			printf("%lld\n",a[i]+b[i]-3);
		}else{
			temp=(long int)sqrt(a[i]*b[i]);
			if(temp*(temp+1)<a[i]*b[i]){
				printf("%ld\n",temp*2-1);
			}else if(temp*(temp+1)==a[i]*b[i]){
				printf("%ld\n",temp*2-2);
			}else if(temp*temp==a[i]*b[i]){
				printf("%ld\n",temp*2-3);
			}else{
				printf("%ld\n",temp*2-2);
			}
		}
	}
//	printf("??????\n");
	//??
	
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&a[i],&b[i]);
   ^