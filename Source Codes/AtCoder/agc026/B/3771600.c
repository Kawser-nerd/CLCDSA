#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12


int main(void)
{
	//?????
	int t;
	llong int a,b,c,d;
	llong int gcd;
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	llong int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	//????????
	scanf("%d",&t);
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<t;i++){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		
		if(b>d){
			printf("No\n");
		}else{
			temp1=b;
			temp2=d;
		while(temp1!=0&&temp2!=0){
				if(temp1>temp2){
					temp1=temp1%temp2;
				}else{
					temp2=temp2%temp1;
				}
			}
			
			gcd=max(temp1,temp2);
			
			if(a-c>gcd){
//				printf("a=%lld,a-c=%lld,gcd=%lld,(a-c)/gcd=%lld\n",a,a-c,gcd,(a-c)/gcd);
				a=a-((a-c-1)/gcd)*gcd;
			}
//			printf("gcd=%lld,a=%lld\n",gcd,a);
			
			if(a>=b){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}
	
	
	
//	printf("??????\n");
	//??
	
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&t);
  ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
   ^