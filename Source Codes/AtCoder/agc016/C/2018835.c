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

#define N_MAX 1000
#define M_MAX 400

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


ull solve () {
	sll i, j, ki, l;

	ull minors = (h / vua) * (w / vub);
	// when the way works successfully?
	// (h*w - minors) * X > minors * ((a*b - 1) * X + 1)
	// hwX - mX > m(abX - X + 1)
	// hwX > m(abX + 1)
	// hwX - mabX > m
	// (hw - mab)X > m
	ull hw_mab = h * w - minors * vua * vub;
	// if this is 0, it means "vua | h, vub | w"
	// ---> whole space will be filled with MINOR blocks without any gaps
	// ---> Oops total sum is minor

	if (hw_mab == 0) goto fail;
	
	ull generalnum = (minors + hw_mab) / hw_mab;
	ull minornum = ((vua * vub - 1) * generalnum + 1);

	puts("Yes");
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			char split = ((j == (w - 1)) ? '\n' : ' ');
			if (!((i + 1) % vua) && !((j + 1) % vub)) {
				printf("-%llu%c", minornum, split);
			} else {
				printf("%llu%c", generalnum, split);
			}
		}
	}

	return 0;

	fail:
	puts("No");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%llu%llu", &h, &w);
	scanf("%llu%llu", &vua, &vub, &vuc, &vud, &vue);

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:91:12: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
     printf("-%llu%c", minornum, split);
            ^
./Main.c:93:12: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘ull {aka long unsigned int}’ [-Wformat=]
     printf("%llu%c", generalnum, split);
            ^
./Main.c: In function ‘main’:
./Main.c:109:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu%llu", &h, &w);
        ^
./Main.c:109:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 3 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
./Main.c:110:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%ll...