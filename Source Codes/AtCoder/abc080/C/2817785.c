#include <stdio.h>
#include <limits.h>

int main(void){
	int N,i,j,k,c=0;
	long ans = LONG_MIN,sum=0;
	scanf("%d",&N);
	int F[N][10],schedule[1024][10];
	long P[N][11];
	for(i=0;i<N;i++){
		for(j=0;j<10;j++){
			scanf("%d",&F[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<=10;j++){
			scanf("%ld",&P[i][j]);
		}
	}
	for(i=0;i<1024;i++){
		int x = 2;
		for(j=0;j<10;j++){
			k = i%x;
			if(k>=(x/2)) schedule[i][j] = 1;
			else		 schedule[i][j] = 0;
			x *= 2;
		}
	}
	
	for(j=1;j<1024;j++){ //j?????????
		sum=0;
		for(i=0;i<N;i++){//?i
			c=0;
			for(k=0;k<10;k++){//???
				if(F[i][k]==1 && schedule[j][k]==1) c++;
			}
			sum+=P[i][c];
		}
		if(ans<sum) ans = sum;
	}
	
	printf("%ld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:12:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&F[i][j]);
    ^
./Main.c:17:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%ld",&P[i][j]);
    ^