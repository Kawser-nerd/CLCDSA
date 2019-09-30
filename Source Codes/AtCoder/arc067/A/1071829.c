#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define Q 1000000007

int main(void){
	int n, i, j;
	unsigned long long int num=1;
	char ar[N+1][N+1];
	int pf[N+1];
	int soe[N+1];

	scanf("%d", &n);
	for(i=2; i<=n; i++){
		soe[i] = 1;
	}
	for(i=2; i*i<=n; i++){
		if(soe[i] == 0) continue;
		for(j=i*2; j<=n; j+=i){
			soe[j] = 0;
		}
	}
	
	for(i=2; i<=n; i++){
		if(soe[i] == 0) continue;
		for(j=1; j*i<=n; j++){
			ar[i][j*i]=1;
			if(j%i == 0) ar[i][j*i] += ar[i][j];
		}
	}
	for(i=2; i<=n; i++){
		if(soe[i] == 0) continue;
		for(j=i; j<=n; j+=i){
			pf[i] += ar[i][j];
		}
	}
	for(i=2; i<=n; i++){
		if(soe[i] != 0){
			num = num * (pf[i]+1);
			num = num % Q;
		}
	}

	printf("%d\n", (int)num);

	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^