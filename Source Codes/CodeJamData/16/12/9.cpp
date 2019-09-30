#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int T, n;
int h[10000];

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		memset(h, 0, sizeof h);
		scanf("%d", &n);
		for (int j = 1; j <= 2 * n - 1; j++)
			for (int p = 1; p <= n; p++) {
				int x;
				scanf("%d", &x);
				h[x] ^= 1;
			}
		printf("Case #%d:", i);
		for (int j = 1; j <= 2500; j++)
			if (h[j])
				printf(" %d", j);
		printf("\n");
	}
}
