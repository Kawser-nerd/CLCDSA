#include<stdio.h>
#include<gmp.h>
#include<stdlib.h>

#define MAXN (1024)
#define MAXT (64)
#define BASE (10)

mpz_t v[MAXN];
mpz_t delta[MAXN];
mpz_t mdc,x,zero,y;

char num[MAXT];

int comp(const void *a,const void *b){
	mpz_t *x = (mpz_t*)a;
	mpz_t *y = (mpz_t*)b;
	
	return mpz_cmp(*x,*y);
}

int main(){
	int nteste,teste,n,i;
	
	for(i=0;i<MAXN;i++){
		mpz_init2(v[i],200);
		mpz_init2(delta[i],200);
	}
	mpz_init2(mdc,200);
	mpz_init2(zero,200);
	mpz_init2(x,200);
	mpz_init2(y,200);
	
	
	scanf("%d",&nteste);
	for(teste=1;teste<=nteste;teste++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf(" %s",num);
			mpz_set_str(v[i],num,BASE);
		}
		qsort(v,n,sizeof(v[0]),comp);
		for(i=0;i<(n-1);i++){
			mpz_sub(delta[i],v[i+1],v[i]);
		}

		mpz_set_si(mdc,(long int)0);
		
		for(i=0;i<(n-1);i++){
			mpz_gcd(mdc,mdc,delta[i]);
//			mpz_out_str(stdout,10,mdc);
//			printf("\n");
		}
		
		mpz_init2(x,200);
		mpz_mod(x,v[0],mdc);
		
		if(mpz_cmp(x,zero) == 0){
			mpz_set_si(y,(long int)0);
		}else{
			mpz_sub(y,mdc,x);
		}
		printf("Case #%d: ",teste);
		mpz_out_str(stdout,10,y);
		printf("\n");
	}
	return 0;
}
