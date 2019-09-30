/* 
	USE the GNU multiple precision arithmetic library (GMP)
	link: http://gmplib.org/
*/

#include <gmp.h>
#include <stdio.h>

int compare_mpz(const void* a, const void* b)
{
	mpz_t* t1=(mpz_t*)a;
	mpz_t* t2=(mpz_t*)b;
	return mpz_cmp(*t1, *t2);
}

int main()
{
	int i, j, c;
	int C, N;
	int MAXB=192;
	char istr[55];
	mpz_t n[1000];
	mpz_t factor;
	mpz_t tmp;
	mpz_t tmp2;
	
	for(i=0;i<1000;i++) 
		mpz_init2(n[i], MAXB);
	mpz_init2(factor, MAXB);
	mpz_init2(tmp, MAXB);
	mpz_init2(tmp2, MAXB);

	scanf("%d", &C);
	for(c=0;c<C;c++) {
		scanf("%d", &N);
		for(i=0;i<N;i++) {
			scanf("%s", istr);
			mpz_set_str(n[i], istr, 10);
		}
		qsort(n, N, sizeof(mpz_t), compare_mpz);

		for(i=1;i<N;i++) {
			mpz_sub(factor, n[i], n[i-1]);
			if(mpz_cmp_ui(factor, 0)!=0) break;
		}

		for(i=i+1;i<N;i++) {
			mpz_sub(tmp, n[i], n[i-1]);
			if(mpz_cmp_ui(tmp, 0)==0) continue;
			mpz_gcd(tmp2, tmp, factor);
			mpz_swap(factor, tmp2);
		}
		printf("Case #%d: ", c+1);
		mpz_mod(tmp, n[0], factor);
		if(mpz_cmp_ui(tmp, 0)==0) printf("0");
		else {
			mpz_sub(tmp2, factor, tmp);
			mpz_out_str(stdout, 10, tmp2);
		}
		/*
		printf("@");
		mpz_out_str(stdout, 10, factor); */
		printf("\n");
/*		for(i=0;i<N;i++) {
			mpz_out_str(stdout, 10, n[i]);
			printf("\n");
		} */
	}
}

			
