#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)

int T;
vector<int> prim;

int main() {
	{
		vector<bool> isprim((1000005+1)/2, true);
		prim.push_back(2);
		for (int p = 3; p <= 1000005; p += 2) {
			if (isprim[(p-1)/2]) {
				prim.push_back(p);
				for (long long k = ((long long)p*p-1)/2; 2*k+1 <= 1000005; k += p)
					isprim[k] = false;
			}
		}
	}
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		long long N;
		scanf("%lld", &N);
		long long S = 1;
		if (N == 1)
			S = 0;
		else {
			for (int ip = 0; ip < prim.size(); ip++) {
				long long p = prim[ip];
				long long n = p*p;
				while(n <= N) {
					S++;
					n *= p;
				}
			}
		}
		printf("%lld\n", S);
	}
	return 0;
}
