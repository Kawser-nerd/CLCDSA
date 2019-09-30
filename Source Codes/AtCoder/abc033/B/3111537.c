#include <stdio.h>

char S[1005][25];
int P[1005];

int main(){

	int N;

	scanf("%d",&N);

	int i;

	int sum=0;

	for(i=0;i<N;i++){
	scanf("%s %d",S[i],&P[i]);
	sum+=P[i];
	}

	for(i=0;i<N;i++){
		if(sum/2<P[i]){
			printf("%s\n",S[i]);
			return 0;
		}
	}
	printf("atcoder\n");

return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %d",S[i],&P[i]);
  ^