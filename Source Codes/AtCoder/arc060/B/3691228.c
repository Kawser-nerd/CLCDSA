#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//?????
	long long int n,s;
	static long long int num[1000010];
	long long int sqrtn;
	
	//??????
	int i;
	long long int j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	long long int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%lld",&n);
	scanf("%lld",&s);
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
//	printf("n=%lld\n",n);

	if(n<s){
		printf("-1");
		return 0;
	}else if(n==s){
		printf("%lld",n+1);
		return 0;
	}

	if(n==2&&s==1){
		printf("2");
		return 0;
	}

	for(j=1;j<n;j++){
//		printf("i=%lld, i*i=%lld\n",i,i*i);
		if(j*j>=n){
			sqrtn=j;
			break;
		}
	}

//	printf("sqrtn=%lld,sqrtn^2=%lld,\n",sqrtn,sqrtn*sqrtn);

	for(i=1;i<sqrtn;i++){
//		printf("i=%d (n-s)%%i=%lld\n",i,(n-s)%i);
		if((n-s)%i==0){
			num[count]=i;
//			printf("num[%d]=%lld\n",count,num[count]);
			count++;
		}
	}
	
	for(i=count;i<2*count;i++){
		num[i]=(n-s)/num[2*count-1-i];
	}
	
	for(i=0;i<2*count;i++){
//		printf("num[%d]=%lld\n",i,num[i]);
		temp=n;
		temp2=0;
		while(temp!=0){
			temp2=temp2+temp%(num[i]+1);
			temp=temp/(num[i]+1);
//			printf("temp=%lld,temp2=%lld\n",temp,temp2);
		}
		if(temp2==s){
			printf("%lld",num[i]+1);
			return 0;
		}
	}
	
//	printf("??????\n");
	//??
	
	printf("-1");
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&s);
  ^