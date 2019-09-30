#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>
#include <string.h>

typedef long long LL;
int getLength(LL x) {
	int res = 0;
	while (x > 0) {
		x = x / 10;
		res++;
	}
	return res;
}

LL nine[16];
char dd[16];
LL solve(LL a) {
	if (a % 10 == 0) {
		return solve(a - 1) + 1;
	}

	int len = getLength(a);
	LL res = 0;
	for (int i = 1; i < len; i++) { 
		int x = (i + 1) / 2;
		int y = i / 2;

		res += nine[y] + nine[x] + 1;
	}
	sprintf(dd, "%lld", a);
	int lll = strlen(dd);
	if (lll != len) {
		fprintf(stderr, "Warning! Unexpected Result");
	}

	int lm = len / 2 - 1;
	int rm = lm + 1;
	LL left, right;
	left = right = 0;
	for (int i = lm; i >= 0; i--) {
		left = left * 10 + (dd[i] - '0');
	}
	for (int i = rm; i < len; i++) {
		right = right * 10 + (dd[i] - '0');
	}

	if (left > 1) {
		res += left;
	}
	res += right;

	return res;
}
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out_", "w", stdout);
	nine[0] = 0;
	for (int i = 1; i <= 15; i++) {
		nine[i] = nine[i - 1] * 10 + 9;
	}
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		LL sol;
		scanf("%lld", &sol);
		sol = solve(sol);
		printf("Case #%d: %lld\n", cs, sol);
	}
	
	return 0;
}