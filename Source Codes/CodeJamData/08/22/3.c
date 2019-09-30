#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

int primes[MAX] = {2, 3, 5, 7};
int numbers[MAX + 1];
int test[MAX + 1];

void precalc_primes() {
	int i;
	for (i = 4; i < 200; i++) {
		int potential = primes[i-1] + 1;
		int found = 0;
		while (!found) {
			int n, is_prime = 1;
			for (n = 0; n < i; n++) {
				if (potential % primes[n] == 0) {
					is_prime = 0;
					potential++;
					break;
				}
			}
			if (is_prime) {
				found = 1;
			}
		}
		primes[i] = potential;
		//printf("Primes[%d] = %d\n", i, potential);
	}
}

int find_first(int p) {
	int i;
	for (i = 0; i < p; i++) {
		if (primes[i] >= p) {
			return i;
		}
	}
	return 0;
}

int share_prime(int x, int y, int p) {
	while (primes[p] <= x) {
		if (x % primes[p] == 0 && y % primes[p] == 0) {
			return 1;
		}
		p++;
	}
	return 0;
}

int find_sets(int A, int B, int p) {
	int total = 0;
	int i, j, k;
	
	for (i = A; i <= B; i++) {
		test[i] = 0;
		numbers[i] = i;
	}
	
	for (i = A; i <= B; i++) {
		for (j = i + 1; j <= B; j++) {
			if (numbers[j] && share_prime(i, j, p)) {
				//printf("Killing %d (%d) = %d\n", j, i, numbers[i]);
				//numbers[j] = numbers[i];
				int old = numbers[j];
				for (k = A; k <= B; k++) {
					if (numbers[k] == old) {
						//printf("Relocating %d\n", k);
						numbers[k] = numbers[i];
					}
				}
			}
		}
	}
	
	for (i = A; i <= B; i++) {
		test[numbers[i]]++;
	}
	
	for (i = A; i <= B; i++) {
		if (test[i]) {
			total++;
		}
	}
	
	return total;
}

int main(int argc, char **argv) {
	int cases;
	int i;
	int A, B, P;
	precalc_primes();
	
	scanf("%d", &cases);
	for (i = 0; i < cases; i++) {
		memset(numbers, 0, 1001 * sizeof(int));
		
		scanf("%d %d %d", &A, &B, &P);
		
		int prime_start = find_first(P);
		
		int sets = find_sets(A, B, prime_start);
		
		printf("Case #%d: %d\n", i+1, sets);
	}
	
	return 0;
}
