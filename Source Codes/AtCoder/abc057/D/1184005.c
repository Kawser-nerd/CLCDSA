#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define S_MAX 1000
#define N_MAX 50
#define M_MAX 50
#define INF 2000000000
#define MOD 1000000007
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;
typedef   signed long long dll;

typedef struct {
	int a;
	int b;
	int c;
} moneydata;

ull n, m;
int a, b;
ull i, j;
int k;

ull v[N_MAX];

ull max(ull a, ull b){
	return (a > b) ? a : b;
}

ull min(ull a, ull b){
	return (a < b) ? a : b;
}

int comp(const void* l, const void* r){
	if (*(ull*)l == *(ull*)r) return 0;
	else if (*(ull*)l > *(ull*)r) return -1;
	else return +1;
}

ull conv(ull n, ull r){
	ull result = 1;
	ull i;
	for (i = 1; i <= r; i++) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

void solve(){
	double maxperiod = 0.0;
	ull ue = 0, shita = 1;
	double eachper;
	ull maxtotal = 0;
	ull result = 0;
	ull eachres;

	int minleft, minright;

	qsort(v, n, sizeof(ull), comp);

	for (i = 0; i < b; i++) {
		maxtotal += v[i];

		if (i < a - 1) continue;

		eachper = (double)maxtotal / (double)(i + 1);
		
		// if (maxperiod < eachper) {
		// printf("%llu * %llu, %llu * %llu\n", ue, (i + 1), maxtotal, shita);
		if (ue * (i + 1) < maxtotal * shita) {
			maxperiod = eachper;
			ue = maxtotal;
			shita = i + 1;
			result = 0;
		} else if (ue * (i + 1) > maxtotal * shita) {
			continue;
		}

		minleft = minright = i;
		while (minleft && v[minleft - 1] == v[minleft]) minleft--;
		while (minright < n - 1 && v[minright + 1] == v[minright]) minright++;

		eachres = conv(minright - minleft + 1, i - minleft + 1);
		// printf("%lld, %lld, %lld\n", i, eachres, result);
		result += eachres;
	}

	printf("%f\n", maxperiod);
	printf("%llu\n", result);
	return;
}

int main (void) {
	scanf("%llu%llu%llu", &n, &a, &b);
	for (i = 0; i < n; i++) scanf("%llu", &v[i]);

	solve();
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:98:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 3 has type ‘int *’ [-Wformat=]
  scanf("%llu%llu%llu", &n, &a, &b);
        ^
./Main.c:98:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 4 has type ‘int *’ [-Wformat=]
./Main.c:98:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu%llu", &n, &a, &b);
  ^
./Main.c:99:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < n; i++) scanf("%llu", &v[i]);
                          ^