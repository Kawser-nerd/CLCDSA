#include<stdio.h>
int main(void){
	int N;
	scanf("%d",&N);
	int L[N];
	int a;
	int sum=0;
	for(a=0;a<N;a++){
		scanf("%d",&L[a]);
		sum+=L[a];
	}
	for(a=0;a<N;a++){
		if(L[a]>=(sum-L[a])){
			printf("No");
			break;
		}else{
			if(a==N-1){
				printf("Yes");
			}
		}
	}
	
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&L[a]);
   ^