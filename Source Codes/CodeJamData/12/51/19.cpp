#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

const int inf = 2147483647;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int maxn = 10000;

struct level {
	int l, p, id;

	friend bool operator<(const level &a, const level &b) {
		long long V = 1ll * a.l * b.p - 1ll * b.l * a.p;

		if(V != 0) return V < 0;
		else return a.id < b.id;
	}
} L[maxn];

int n;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &n);

		for(int i=0; i<n; i++) {
			scanf("%d", &L[i].l);
			L[i].id = i;
		}
		for(int i=0; i<n; i++) {
			scanf("%d", &L[i].p);
		}

		sort(L, L+n);

		printf("Case #%d:", test);

		for(int i=0; i<n; i++) printf(" %d", L[i].id);

		printf("\n");
	}
	return 0;
}
