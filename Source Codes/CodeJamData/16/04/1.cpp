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

int T, K, S, C;
set <long long > Set;

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d:", i);
		scanf("%d%d%d", &K, &C, &S);
		if (C * S < K) {
			printf(" IMPOSSIBLE\n");
			continue;
		}else {
			int t = 0;
			Set.clear();
			for (int j = 1; j <= S; j++) {
				long long now = 0;
				for (int p = 1; p <= C; p++)
					now = now * K + t, t = (t + 1) % K;
				now += 1;
				if (Set.count(now)) {
					now = 1;
					while (Set.count(now))
						now += 1;
				}
				Set.insert(now);
				printf(" %lld", now);
			}
			printf("\n");
		}
	}
}
