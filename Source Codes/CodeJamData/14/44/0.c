#include <stdio.h>
#include <stdlib.h>

int N, M;
char strs[100][1001];

typedef struct _node *node;

struct _node {
	node next[26];
};

int upTo;
struct _node cache[10000];

node newNode() {
	int i;
	node n = &cache[upTo++];
	for (i = 0; i < 26; i++) {
		n->next[i] = NULL;
	}
	return n;
}

void addStr(node at, char *str) {
	if (!*str) return;
	int l = *str - 'A';
	if (at->next[l] == NULL) {
		at->next[l] = newNode();
	}
	addStr(at->next[l], str + 1);
}

int findA(int conf) {
	int group[10];
	int seen[4];
	int i;
	for (i = 0; i < N; i++) {
		seen[i] = 0;
	}
	for (i = 0; i < M; i++) {
		group[i] = conf % N;
		seen[group[i]] = 1;
		conf /= N;
	}
	
	for (i = 0; i < N; i++) {
		if (!seen[i]) {
			return -1;
		}
	}
	upTo = 0;
	node roots[4];
	for (i = 0; i < N; i++) {
		roots[i] = newNode();
	}
	for (i = 0; i < M; i++) {
		addStr(roots[group[i]], &strs[i][0]);
	}
	return upTo;
}


void handle() {
	scanf ("%d %d ", &M, &N);
	int i;
	for (i = 0; i < M; i++) {
		scanf ("%s ", &strs[i][0]);
	}
	int amoWa = 1;
	for (i = 0; i < M; i++) {
		amoWa *= N;
	}
	int maxA = 0;
	int amoW = 0;
	for (i = 0; i < amoWa; i++) {
		int ans = findA(i);
		if (ans > maxA) {
			maxA = ans;
			amoW = 1;
		} else if (ans == maxA) {
			amoW++;
		}
	}
	printf ("%d %d\n", maxA, amoW);
}

int main() {
	int t;
	scanf ("%d ", &t);
	int i;
	for (i = 0; i < t; i++) {
		printf ("Case #%d: ", i + 1);
		handle();
	}
	return 0;
}