/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 300000
#define M_MAX 200000

typedef struct {
	int32_t a;
	int32_t b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	hwll a;
	hwll b;
} linell;


typedef struct {
	ull s;
	ull t;
	int32_t c;
} struct_a;

typedef struct {
	int32_t from;
	int32_t to;
	sll cost;
} struct_b;

ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
size_t slen;
size_t tlen;
char ch, dh;

sll a[N_MAX];

hwll arr[N_MAX];

int32_t pullcomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

ull solve () {
	sll i, j, ki;

	qsort(a, n, sizeof(ull), pullcomp);

	ull kinds = 0;
	i = 0;
	while (i < n) {
		j = i;
		while (j < n && a[j] == a[i]) j++;
		arr[kinds].a = a[i];
		arr[kinds].b = j - i;
		kinds++;

		i = j;
	}

	if (arr[0].b > 2) goto fail;
	
	ull maxnum = ((arr[0].b == 1) ? a[0] * 2 : a[0] * 2 - 1);
	if (kinds != (maxnum - a[0] + 1) || arr[kinds - 1].a != maxnum) goto fail;

	for (i = 1; i < kinds; i++) {
		if (arr[i].b < 2) goto fail;
	}

	puts("Possible");
	return 0;

	fail:
	puts("Impossible");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%llu", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}

	solve();

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:118:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:118:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:120:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%llu", &a[i]);
         ^
./Main.c:118:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n, &m);
  ^
./Main.c:120:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &a[i]);
   ^