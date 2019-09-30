#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

using namespace std;
typedef long long LL;
typedef function<int(int)> VALF;

#define pb push_back
#define mt make_tuple
#define SZ(V) ((int)((V).size()))
int N, L;
char G[128][64];
char B[64];
int main() {
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++) scanf("%s", G[i]);
		scanf("%s", B);
		bool pos = true;
		for (int i = 0; i < N; i++) {
			if (!strcmp(G[i], B)) pos = false;
		}
		printf("Case #%d: ", tc);
		if (!pos) printf("IMPOSSIBLE");
		else {
			for (int i = 0; i < L; i++) {
				printf("%c?", '1'-B[i]+'0');
			}
			printf(" ");
			if (L <= 1) printf("%c", '1' - B[0] + '0');
			else {
				for (int i = 0; i < L - 1; i++) {
					char gep = B[i];
					char rep = B[i+1];
					if (rep == gep) printf("%c", rep);
					else printf("%c%c", rep, gep);
				}
			}
		}
		printf("\n");
	}
	return 0;
}