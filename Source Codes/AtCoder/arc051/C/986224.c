#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <regex.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define alloc(type,size) calloc(sizeof(type),size)

#define MOD 1000000007


int argmin(lli *a,int n){
	int i;
	int minmem = INT_MAX;
	int ret;
	for(i=0;i<n;i++){
		if(a[i] < minmem){
			minmem = a[i];
			ret = i;
		}
	}
	return ret;
}

int comp(const void *a,const void *b){
	return (*(lli*)a - *(lli*)b) < 0 ? -1 : 1;
}

int main(void){
	int n,a,b;
	lli *ai;
	lli mul;
	lli mula;

	int i,j,k;
	int maximum = 0;

	scanf("%d%d%d",&n,&a,&b);
	ai = alloc(lli,n);

	for(i=0;i<n;i++){
		scanf("%lld",&ai[i]);
		if(ai[i] > maximum){
			maximum = ai[i];
		}
	}
	if(a == 1){
		qsort(ai,n,sizeof(lli),comp);
		for(i=0;i<n;i++){
			printf("%lld\n", ai[i] % MOD);
		}
		return 0;
	}
	while(ai[(i = argmin(ai,n))]*a < maximum && b > 0) ai[i] *= a,b--;
	if(b==0){
		qsort(ai,n,sizeof(lli),comp);
		for(i=0;i<n;i++){
			printf("%lld\n", ai[i] % MOD);

		}
		return 0;
	}
	k = b % n;
	for(i=0;i<k;i++){
		ai[argmin(ai,n)] *= a;
	}
	qsort(ai,n,sizeof(lli),comp);
	k = b / n;
	mul = a;
	mula = 1;
	for(i=1;i != 0;i = i << 1){
		if(k & i){
			mula *= mul;
			mula %= MOD;
		}
		mul *= mul;
		mul %= MOD;
	}
	for(i=0;i<n;i++){
		ai[i] %= MOD;
		printf("%lld\n", (ai[i] * mula) % MOD);
	}



    return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&ai[i]);
   ^