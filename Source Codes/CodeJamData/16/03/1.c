#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define NUM_PRIMES 3

static const int primes[NUM_PRIMES] = {3, 5, 7}; //, 11, 13};//, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127};

static int pow_mod_prime[9][NUM_PRIMES][32];

static void init_table(void) {
	for(int base = 2; base <= 10; base++) {
		for(int i = 0; i < NUM_PRIMES; i++) {
			int v = 1;
			int p = primes[i];
			for(int j = 0; j < 32; j++) {
				pow_mod_prime[base-2][i][j] = v;
				v = (v * base) % p;
			}
		}
	}
}

static int go(int j, int n);

int main(void) {
	init_table();

	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d:\n", i);
		int j;
		int n;
		scanf("%d %d", &n, &j);
		go(j, n);
	}
	return 0;
}

static void print_binary(int n, int t) {
	for(int i = n-1; i >= 0; i--) {
		printf((t & (1 << i)) ? "1" : "0");
	}
}

static int test(int n, int t, int base) {
	for(int i = 0; i < NUM_PRIMES; i++) {
		int sum = 0;
		int p = primes[i];
		for(int j = 0; j < n; j++) {
			if(t & (1 << j)) sum += pow_mod_prime[base-2][i][j];
			//printf("added to sum: pow_mod_prime[base=%d][prime=%d][pow=%d]=%d  sum now %d\n",base,p,j,pow_mod_prime[base-2][i][j],sum);
		}
		//printf("DEBUG: sum of ");
		//print_binary(n,t);
		//printf(" mod prime %d base %d is %d = %d\n",p,base,sum,sum%p);
		if(sum%p == 0) return p;
	}
	return 0;
}

static int go(int j, int n) {
	for(uint32_t t = (1 << (n-1)) + 1; j != 0 && (t & (1 << (n-1))); t+=2) {
		int ans[9];
		int base;
		for(base = 2; base <= 10; base++) {
			int result = test(n, t, base);
			if(result == 0) break;
			ans[base-2] = result;
		}
		if(base == 11) {
			print_binary(n,t);
			for(int base = 2; base <= 10; base++){
				printf(" %d", ans[base-2]);
			}
			printf("\n");
			j--;
		}
	}
	if(j != 0) printf("FAILED: %d remaining\n", j);
}
