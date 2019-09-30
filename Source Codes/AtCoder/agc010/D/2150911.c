/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 200000
#define M_MAX 200000

#ifdef __cplusplus
#include <queue>
#include <stack>
// #include <tuple>
#include <set>
#include <map>

// using namespace std; // HELL
using std::queue;
using std::priority_queue;
using std::stack;
// using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;

#endif

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



const hw vector8[8] = {
	{-1, -1},
	{-1,  0},
	{-1, +1},
	{ 0, -1},
	{ 0, +1},
	{+1, -1},
	{+1,  0},
	{+1, +1}
};

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

ull gcd (ull x, ull y) {
	if (x < y) {
		return gcd(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

sll a[N_MAX];

ull solve () {
	sll i, j, ki;
	// ull result = 0;
	sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	ull item;
	ull *dpcell;

	ull evens = 0;

	bool takaflag = true;
	bool winflag;

	while (true) {
		evens = 0;

		ull ones = 0;
		ull finalodd = BIG;
		for (i = 0; i < n; i++) {
			if (a[i] == 1) ones++;
			if (a[i] % 2 == 0) {
				evens++;
			} else {
				finalodd = i;
			}
		}
		if (ones) {
			winflag = (evens % 2 == 1);
			break;
		}

		if (evens % 2 == 1) {
			winflag = true;
			break;
		}
		if (evens < n - 1) {
			winflag = false;
			break;
		}

		if (finalodd == BIG) {
			winflag = false;
			break;
		}
		a[finalodd]--;

		ull allgcd = a[0];
		for (i = 0; i < n; i++) {
			allgcd = gcd(allgcd, a[i]);
		}
		for (i = 0; i < n; i++) {
			a[i] /= allgcd;
		}

		takaflag = !takaflag;
	}

	if ((winflag ? 1 : 0) == (takaflag ? 1 : 0)) {
		goto success;
	} else {
		goto fail;
	}

	return 0;

	success:
	puts("First");
	return 0;

	fail:
	puts("Second");
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
./Main.c:193:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘ull * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu", &n, &m);
        ^
./Main.c:193:8: warning: too many arguments for format [-Wformat-extra-args]
./Main.c:195:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘sll * {aka long int *}’ [-Wformat=]
   scanf("%llu", &a[i]);
         ^
./Main.c:193:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n, &m);
  ^
./Main.c:195:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &a[i]);
   ^