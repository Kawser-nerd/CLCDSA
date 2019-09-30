#include <stdio.h>
#include <string.h>

int caseN, N;
int a, b, pp;
int count, i;
int wh[10001];
int prime[10001];
int p[10001];
int j, tmp, tmp2;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int test(int a, int b) {
	int tmp = gcd(a, b);
	int i;

	for (i = pp; i <= tmp; i++)
		if (prime[i] && tmp%i==0)
			return 1;
	
	return 0;
}

int isPrime(int n) {
	int i;

	if (n == 0) return 0;
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;

	for (i = 3; i*i <= n; i+=2)
		if (n%i == 0)
			return 0;

	return 1;
}

int find(int n) {
	if (p[n] == n) return n;
	return find(p[n]);
}

int main() {
	for (i = 0; i <= 10000; i++)
		prime[i] = isPrime(i);

	scanf("%d", &caseN);
	for (N = 1; N <= caseN; N++) {
		scanf("%d%d%d", &a, &b, &pp);

		for (i = a; i <= b; i++) p[i] = i;
		
		for (i = a; i < b; i++)
			for (j = i+1; j <= b; j++) 
				if (test(i, j)) {
					tmp = find(i);
					tmp2 = find(j);
					p[tmp2] = tmp;
				}
		
		count = 0;
		for (i = a; i <= b; i++) {
			tmp = find(i);
			if (tmp == i) count++;
		}

		printf("Case #%d: %d\n", N, count);
	}
	return 0;
}

