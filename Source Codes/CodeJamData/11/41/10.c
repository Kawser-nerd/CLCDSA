#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
	int b;
	int e;
	int w;
} no;

int cmp(const void *a, const void *b) {
	no *aux = (no *) a;
	no *aux2 = (no *) b;
	
	if ((*aux).b < (*aux2).b) {
		return -1;	
	} else {
		return 1;	
	}
}

int cmp2(const void *a, const void *b) {
	no *aux = (no *) a;
	no *aux2 = (no *) b;
	
	if ((*aux).w < (*aux2).w) {
		return -1;	
	} else if ((*aux).w == (*aux2).w){
		if ((*aux).b < (*aux2).b) {
			return -1;
		} else {
			return 1;	
		}
	} else {
		return 1;	
	}
}

int main() {
	int i, j, k, l, m, n, o, p, t, T, x, s, r;
	double resp, a, b, c, d;
	no *vet;
	vet = (no *) malloc(sizeof(no)*1010);
	scanf("%d", &T);
	for (o = 1; o <= T; o++) {
		scanf("%d %d %d %d %d", &x, &s, &r, &t, &n);
		k = 0;
		for (i =0; i < n; i++) {
			scanf("%d %d %d", &vet[i].b, &vet[i].e, &vet[i].w);	
			k = k + vet[i].e - vet[i].b;
		}
		j = n;
		vet[j].b = 0;
		vet[j].e = x - k;
		vet[j].w = 0;
		j++;
		qsort(vet, j, sizeof(no), cmp2);
		
	//	for (i = 0; i < j; i++) {
	//		printf("%d %d %d\n", vet[i].b, vet[i].e, vet[i].w)	;
	//	}
		
		resp = 0;
		a = t;
		for (i = 0; i < j; i++) {
			c = vet[i].e - vet[i].b;
			b = vet[i].w + r;
	//		printf("%lf %lf %lf\n", c, b, a);
			if (a == 0.0) {
	//			printf("1\n");
				resp = resp + (c/(double) (vet[i].w + s));
	//			printf("resp %lf\n", resp);
			} else if ((c/b) <= a) {
	//			printf("2\n");
				resp = resp + (c/b);
				a = a - (c/b);	
	//			printf("a %lf\n", a);
			} else {
	//			printf("3\n");
				d = b*a;
				resp = resp + a;
				a = 0.0;
				c = c-d;
				resp = resp + (c/(double) (vet[i].w + s));
			}
		}
		printf("Case #%d: %lf\n", o, resp);
	}
	
	return 0;	
}
