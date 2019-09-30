#include<stdio.h>

typedef unsigned nat;
typedef unsigned char nat8;
typedef unsigned short nat16;

typedef enum {departure, arrival} kind_t;
typedef nat8 term_t;
typedef nat16 time_t;

typedef struct {
	kind_t kind;
	term_t term;
	time_t time;
} event;

#define E_SIZE 512

event E[E_SIZE];

int ecmp(const void* pa, const void* pb) {
	const event *a = pa, *b = pb;

	if (a->time < b->time)
		return -1;
	if (a->time > b->time)
		return 1;
	if (a->kind == arrival)
		return b->kind == departure ? -1 : 0;
	return b->kind == departure ? 0 : 1;
}

int main() {
	nat tc, cs, tt, na, nb, evs, i, dh, dm, d, ah, am, a, t[2], c[2], term;

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%u%u%u", &tt, &na, &nb);
		evs = 0;
		for (i = 0; i != na; ++i) {
			scanf("%u:%u%u:%u", &dh, &dm, &ah, &am);
			d = 60*dh + dm;
			a = 60*ah + am;
			E[evs++] = (event) {
				.kind = departure,
				.term = 0,
				.time = d
			};
			E[evs++] = (event) {
				.kind = arrival,
				.term = 1,
				.time = a+tt
			};
		}
		for (i = 0; i != nb; ++i) {
			scanf("%u:%u%u:%u", &dh, &dm, &ah, &am);
			d = 60*dh + dm;
			a = 60*ah + am;
			E[evs++] = (event) {
				.kind = departure,
				.term = 1,
				.time = d
			};
			E[evs++] = (event) {
				.kind = arrival,
				.term = 0,
				.time = a+tt
			};
		}

		qsort(E, evs, sizeof(event), ecmp);

		t[0] = t[1] = 0;
		c[0] = c[1] = 0;
		for (i = 0; i != evs; ++i) {
			if (E[i].kind == arrival)
				++t[E[i].term];
			else {
				term = E[i].term;
				if (t[term] == 0) {
					++t[term];
					++c[term];
				}
				--t[term];
			}
		}

		printf("Case #%u: %u %u\n", cs+1, c[0], c[1]);
	}

	return 0;
}


