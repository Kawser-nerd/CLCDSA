#include <stdio.h>
void pushmodtoans(int i,int mod);
int ans[10000]={};

int main(void){
	int N;
	int mod;
	scanf("%d",&N);
	int w = N;
	int i = 0;
	
	if ( N ==0){
		printf("0");
		return 0;
	}
	//N?-2???????????
	//N?1??????????
	while ( N!=1){
		if ( N%(-2) == -1){
			mod = N%(-2) +2;
			N = N/(-2);
			N +=1;
			pushmodtoans(i,mod);
			i++;
		}else{
			mod = N%(-2);
			N /=(-2);
			pushmodtoans(i,mod);
			i++;
		}
		//printf("%d ?-2?????\n%d???%d\n",w,N,mod);
		w = N;
	}
	//printf("i=%d",i);
	printf("%d",N);
	for(i;i>0;i--){
		printf("%d",ans[i-1]);
	}
	//???????????????????
	
	return 0;
}
	
void pushmodtoans(int i,int mod){
	ans[i]=mod;
	i++;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^