#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

typedef struct card {
	int value;
	struct card *next, *prev;
} Card;

Card deck[MAX];

void init(int k) {
	int i;
	for (i = 0; i < k; i++) {
		deck[i].value = 0;
		deck[i].next = &deck[i+1];
		deck[i].prev = &deck[i-1];
	}
	deck[k-1].next = &deck[0];
	deck[0].prev = &deck[k-1];
}

void find_perfect(int k) {
	int i, j;
	int cards = k;
	init(k);
	Card *c = &deck[k-1];
	
	for (i = 1; i <= k; i++) {
		
		for (j = 0; j < (i % cards); j++) {
			c = c->next;
		}
		/* Remove current */
		c->value = i;
		c->prev->next = c->next;
		c->next->prev = c->prev;
		c = c->prev;
		cards--;
	}
}

void print(int k) {
	int i;
	for (i = 0; i < k; i++) {
		printf(" %d", deck[i].value);
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int cases;
	int i;
	
	scanf("%d", &cases);
	for (i = 0; i < cases; i++) {
		int k, n, j;
		scanf("%d", &k);
		find_perfect(k);
		//print(k);
		printf("Case #%d:", i+1);
		
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			int d;
			scanf("%d", &d);
			printf(" %d", deck[d-1].value);
		}
		printf("\n");
	}
	
	return 0;
}
