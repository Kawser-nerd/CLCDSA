#include <stdio.h>
#include <stdlib.h>

int comparator(const void *e1, const void *e2) {
	unsigned elem1 = *(unsigned*) e1;
	unsigned elem2 = *(unsigned*) e2;
	if(elem1 < elem2) return 1;
	else if(elem1 > elem2) return -1;
	else return 0;
}

int main() {
	unsigned ncases;
	unsigned P, K, L;
	scanf("%d\n", &ncases);
	for(int ncase = 1; ncase <= ncases; ncase++) {
		scanf("%u %u %u\n", &P, &K, &L);
		unsigned freq[L];
		for(int i = 0; i < L; i++) scanf("%u", &freq[i]);
		qsort(freq, L, sizeof(unsigned), comparator);
		unsigned long pushes = 0;
		if(K * P < L) printf("Case #%u: impossible\n", &ncase);
		else {
			for(int i = 0; i < L; i++) pushes += freq[i] * (1+i/K);
			printf("Case #%u: %lu\n", ncase, pushes);
		}
	}
}
