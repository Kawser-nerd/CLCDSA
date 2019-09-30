#include <stdio.h>
#include <inttypes.h>

#define MAX 100000

int N;
int64_t A[MAX];
int64_t sa[MAX];
int64_t keisu[MAX];
int64_t a_tono_sa[MAX];
int64_t left_keisu, right_keisu;
int64_t a_value;

int main(void) {
	int i;
	if (scanf("%d", &N) != 1) return 1;
	/* 1*a + 2*b + 3*c + 4*d + 5*e = 6 ???? */
	for (i = 0; i < N; i++) {
		if (scanf("%"SCNd64, &A[i]) != 1) return 1;
	}
	/*    a +   b +   c +   d - 4*e = 3 ???? */
	for (i = 1; i < N; i++) {
		sa[i - 1] = A[i] - A[i - 1];
	}
	sa[N - 1] = A[0] - A[N - 1];
	/* 5*d - 5*e = 0 ???? */
	for (i = 1; i < N; i++) {
		keisu[i - 1] = sa[i - 1] - sa[i];
	}
	keisu[N - 1] = sa[N - 1] - sa[0];

	/* ?????????????? */
	for (i = 0; i < N; i++) {
		if (keisu[i] % N != 0) {
			puts("NO");
			return 0;
		}
	}

	/* N-2?a?N-3?b?… */
	/* a_tono_sa[0]?a???????? */
	a_tono_sa[N - 1] = keisu[N - 1] / N; /* e = a + keisu[N - 1]/N */
	for (i = 0; i < N - 1; i++) {
		a_tono_sa[N - 2 - i] = a_tono_sa[(N - 2 - i) + 1] + keisu[i] / N;
	}

	/* 1*a + 2*b + 3*c + 4*d + 5*e = 6 ??????? */
	left_keisu = (int64_t)N * (int64_t)(N + 1) / 2;
	right_keisu = A[0];
	for (i = 0; i < N; i++) {
		right_keisu -= (i + 1) * a_tono_sa[i];
	}

	if (right_keisu % left_keisu != 0) {
		/* a?????? */
		puts("NO");
		return 0;
	}

	a_value = right_keisu / left_keisu;
	for (i = 0; i < N; i++) {
		if (a_value + a_tono_sa[i] < 0) {
			/* ???????????????? */
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	return 0;
}

/*

?????????????????k?????
4 *   ***
3 **  *
5 *** **

2 *   *
4 **  **
6 *** ***

3 *   **
5 **  ***
4 *** *

???????????????N*(N+1)/2???(1???????????????)
??????????? {4, 1, 1}

?2
 6 ******
 9 *********
12 ************
10 **********
 8 ********

12?5*2????->??3???
 6 ***   **    *
 9 ****  ***   **
12 ***** ****  ***
10 *     ***** ****
 8 **    *     *****

1*a + 2*b + 3*c + 4*d + 5*e = 6
2*a + 3*b + 4*c + 5*d + 1*e = 9
3*a + 4*b + 5*c + 1*d + 2*e = 12
4*a + 5*b + 1*c + 2*d + 3*e = 10
5*a + 1*b + 2*c + 3*d + 4*e = 8

   a +   b +   c +   d - 4*e = 3
   a +   b +   c - 4*d +   e = 3
   a +   b - 4*c +   d +   e = -2
   a - 4*b +   c +   d +   e = -2
-4*a +   b +   c +   d +   e = -2

5*d - 5*e = 0
5*c - 5*d = 5
5*b - 5*c = 0
5*a - 5*b = 0
5*e - 5*a = -5

d = e
c = d + 1
b = c
a = b
e = a - 1

a
b = c = d + 1 = e + 1 = a - 1 + 1 = a
c = d + 1 = a
d = e = a - 1
e = a - 1

a + b + c +   d - 4*e     = 3
a + a + a + a-1 - 4*(a-1) = 3
0=0

1*a + 2*b + 3*c + 4*d + 5*e = 6
1*a + 2*a + 3*a + 4*(a-1) + 5*(a-1) = 6
15*a = 15
a = 1
b = 1
c = 1
d = 0
e = 0

-------------------------------------

?3
1*a + 2*b + 3*c + 4*d = 1
2*a + 3*b + 4*c + 1*d = 2
3*a + 4*b + 1*c + 2*d = 3
4*a + 1*b + 2*c + 3*d = 1

   a +   b +   c - 3*d = 1
   a +   b - 3*c +   d = 1
   a - 3*b +   c +   d = -2
-3*a +   b +   c +   d = 0

4*c - 4*d = 0
4*b - 4*c = 3
4*a - 4*b = -2
4*d - 4*a = -1

a, b, c, d ????????->a, b, c, d????????????

-------------------------------------

1*a + 2*b + 3*c = 4
2*a + 3*b + 1*c = 1
3*a + 1*b + 2*c = 1

   a +   b - 2*c = -3
   a - 2*b +   c = 0
-2*a +   b +   c = 3

3*b - 3*c = -3
3*a - 3*b = -3
3*c - 3*a = 6

?????????????????????

*/