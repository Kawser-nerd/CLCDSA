#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ????????????

#define LL long long

#define MOD (1000000000LL + 7LL)

#define AB_MAX 1000000000LL

typedef struct{
	LL a;
	int m;
}a_arr;

int a_arr_cmp(const void *pa,const void *pb)
{
	const a_arr *a=(const a_arr *)pa;
	const a_arr *b=(const a_arr *)pb;
	LL aa = a->a, ab = b->a;
	return aa-ab;
}

int main(void)
{
	LL N,A,B;
	scanf("%lld %lld %lld\n",&N,&A,&B);
	a_arr a[N];
	LL i;
	for (i=0;i<N;i++){
		scanf("%lld ",&a[i].a);
		a[i].m=0;
	}
	LL B_each=0,B_mod=0;
	if (A==1){
		qsort(a,N,sizeof(a_arr),a_arr_cmp);
		B_each = B_mod = 0;
	}
	else if (N>1){
		while (B>0){
			qsort(a,N,sizeof(a_arr),a_arr_cmp);
			if (a[0].a * A >= a[N-1].a)break;
			a[0].a *= A;
			B--;
		}
		qsort(a,N,sizeof(a_arr),a_arr_cmp);
		B_each = B / N;
		B_mod = B % N;
	}
	for (i=0;i<N;i++){
		a[i].m+=B_each;
		if (i<B_mod){
			a[i].m++;
		}
	}
	for (i=0;i<N;i++){
		int idx = (i+B_mod)%N;
		LL ret = a[idx].a;
		ret %= MOD;
		int m = a[idx].m;
		LL Aexp = A;
		while (m > 0){
			if (m & 0x1){
				ret *= Aexp;
				ret %= MOD;
			}
			Aexp*=Aexp;
			Aexp %= MOD;
			m = m >> 1;
		}
		printf("%lld",ret);
		if (i==N-1)printf("\n");
		else printf(" ");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld\n",&N,&A,&B);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld ",&a[i].a);
   ^