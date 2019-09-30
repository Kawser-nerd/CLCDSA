#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		int n; scanf("%d", &n);
		int ans = 0;
		for(int i = 0, t; i < n; ++i) {
			scanf("%d\n", &t);
			if(t > i) ans++;
		}
		printf("Case #%d: ", kase);
		if(ans >= n/2 + n/100) puts("BAD");
		else puts("GOOD");
	}
	return 0;
}
