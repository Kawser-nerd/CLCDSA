#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	//?????
	long long int n,x;
	long long int a,b;
	
	//??????
	int i,j,k,l;
	int flag=0;
	long long int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int min;
	//????????
	scanf("%lld %lld",&n,&x);
	
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}*/
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	ans=n;
	a=x;
	b=n-x;
	
	while(flag==0){
		if(a==b){
			ans=ans+a;
			flag=1;
		}else if(a<b){
			if(b%a!=0){
				ans=ans+(b/a)*a*2;
				b=b%a;
			}else{
				ans=ans+(b/a-1)*a*2;
				b=a;
			}
		}else{
			if(a%b!=0){
				ans=ans+(a/b)*b*2;
				a=a%b;
			}else{
				ans=ans+(a/b-1)*b*2;
				a=b;
			}
		}
	}
	
//	printf("??????\n");
	//??
	
	printf("%lld",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&x);
  ^