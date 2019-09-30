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
	long long int n;
	long long int a[100010];
	long long int sum;
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	long long int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%lld",&n);
	
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	a[n]=a[0];
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	if(n==1){
		printf("YES\n");
		return 0;
	}
	
	sum=0;
	for(i=0;i<n;i++){
		sum=sum+a[i];
	}
	
	if(sum%(n*(n+1)/2)!=0){
		printf("NO\n");
		return 0;
	}else{
		temp=(sum/(n*(n+1)/2));
	}
	
	temp2=temp;
	for(i=0;i<n;i++){
		if((temp+a[i]-a[i+1])%n!=0||(temp+a[i]-a[i+1])/n<0){
			printf("NO\n");
			return 0;
		}else{
			temp2=temp2-(temp+a[i]-a[i+1])/n;
		}
	}
	
	
//	printf("??????\n");
	//??
	
	if(temp2==0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^