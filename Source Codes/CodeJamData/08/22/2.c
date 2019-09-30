#include <stdio.h>
#include <stdlib.h>

char isprime[1000010];
int p[1000010], rank[1000010], un[1000010];

long long min(long long a, long long b) { return ( a < b ? a : b ); }

int ask(int w) {
	int i;
	
	for (i=2; i*i <= w; i++) {
		if ( w%i == 0 ) return 0;
	}
	
	return 1;
}

int Find(int x) {
	if ( p[x] != x ) p[x] = Find(p[x]);
	return p[x];
}

int Union(int x, int y) {
	x = Find(x); y = Find(y);
	
	if ( rank[x] > rank[y] ) {
		p[y] = x;
	}
	else {
		p[x] = y;
		if ( rank[x] == rank[y] ) rank[y]++;
	}
}

long long gcd(long long a, long long b) {
	if ( b == 0 ) return a;
	return gcd(b, a%b);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int T, test;
	long long i, j, k, A, B, P, ans;
	
	for (i=2; i<=1000000; i++) isprime[i] = ask(i);
	
	scanf("%d", &T);
	for(test=1; test<=T; test++) {
		scanf("%lld %lld %lld", &A, &B, &P);
		
		for (i=A; i<=B; i++) {
			p[i - A] = i-A;
			rank[i - A] = 0;
		}
		
		for (k=P; k<=min(1000000,B-A+2); k++) {
			if ( !isprime[k] ) continue;
			
			i = A + (k - A%k)%k;
			if ( i > B ) continue;
			
			for (j=i; j<=B; j+=k) {
				if ( j%k == 0 ) {
					Union(i-A, j-A);
				}
			}
		}
		
		for (i=A; i<=B; i++) {
			Find(i-A);
			un[i-A] = 0;
		}
		
		ans = 0;
		for (i=A; i<=B; i++) {
			if ( !un[ p[i - A] ] ) {
				un[ p[i - A] ] = 1;
				ans++;
			}
		}
		
		printf("Case #%d: %d\n", test, ans);
	}
	
	return 0;
}
