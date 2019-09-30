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
#include <string.h>
using namespace std;
typedef long long LL;
typedef function<int(int)> VALF;

#define pb push_back
#define mt make_tuple
#define SZ(V) ((int)((V).size()))

char stk[30000];
int head;
char inp[30000];
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", inp);
		int len = strlen(inp);
		fprintf(stderr, "%d\n", len);
		head = 0;
		int point = 0;
		for (int i = 0; i < len; i++) {
			if (head > 0 && stk[head - 1] == inp[i]) {
				head--;
				point += 10;
			}
			else {
				stk[head++] = inp[i];
			}
		}
		point += (head / 2) * 5;
		printf("Case #%d: %d\n", tc, point);
	}
	return 0;
}