#include<stdio.h>

typedef unsigned nat;

#define INFINITY 2000000

typedef struct {
	nat gate, change;
	nat zero, one;
} gate;

#define N_SIZE (16*1024)

gate A[N_SIZE];

inline nat min(nat x, nat y) {
	return x < y ? x : y;
}

int main() {
	nat tc, cs;
	nat n, target;
	nat i, g, c;
	nat v, x;
	nat a, b;
	nat and, or;
	nat inter;

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%u%u", &n, &target);
		inter = (n-1)/2;

		for (i = 0; i != inter; ++i) {
			scanf("%u%u", &g, &c);
			A[i].gate = g;
			A[i].change = c;
		}

		for (i = inter; i != n; ++i) {
			scanf("%u", &x);
			A[i].one = x ? 0 : INFINITY;
			A[i].zero = x ? INFINITY : 0;
		}

		for (i = inter; i != 0;) {
			--i;

			a = 2*i+1;
			b = 2*i+2;

			or = min(A[a].one, A[b].one);
			and = A[a].one + A[b].one;

			v = A[i].gate ? and : or;
			if (A[i].change) {
				x = 1 + (!A[i].gate ? and : or);
				if (x < v)
					v = x;
			}

			if (v > INFINITY)
				v = INFINITY;

			A[i].one = v;

			or = A[a].zero + A[b].zero;
			and = min(A[a].zero, A[b].zero);

			v = A[i].gate ? and : or;
			if (A[i].change) {
				x = 1 + (!A[i].gate ? and : or);
				if (x < v)
					v = x;
			}

			if (v > INFINITY)
				v = INFINITY;

			A[i].zero = v;
		}

		printf("Case #%u: ", cs+1);
		v = target ? A[i].one : A[i].zero;
		if (v < INFINITY)
			printf("%u\n", v);
		else
			puts("IMPOSSIBLE");
	}

	return 0;
}


