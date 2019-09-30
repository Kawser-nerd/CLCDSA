#include <stdio.h>
#include <stdlib.h>

struct ab{
	long a;
	long b;
};
int cmp(const void *a,const void *b){
	long long x = ((struct ab*)a)->a - ((struct ab*)b)->a;
	if( x>0){
		return 1;
	}else if (x == 0 ){
		return 0;
	}else if (x<0){
		return -1;
	}
}
int main(void){
	long long N,M;
	int i,j;
	
	scanf("%lld%lld",&N,&M);
	struct ab ab[N];
	for(i=0;i<N;i++){
		scanf("%lld%lld",&ab[i].a,&ab[i].b);
	}
	qsort(ab,N,sizeof(struct ab),cmp);
	//???????????
	int count = 0;
	long long ans = 0;
	
		for(i=0;i<N;i++){
			if( (M-count) > ab[i].b){
				count += ab[i].b;
				ans   += ab[i].b * ab[i].a;
			}else{
				ans += (M-count)*ab[i].a;
				break;
			}
		}
	
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘long int *’ [-Wformat=]
   scanf("%lld%lld",&ab[i].a,&ab[i].b);
         ^
./Main.c:25:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘long int *’ [-Wformat=]
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&N,&M);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&ab[i].a,&ab[i].b);
   ^