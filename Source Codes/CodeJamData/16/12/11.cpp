#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int N;
	for (int tc = 1; tc <= T; tc++) {
		vector<int> sol;
		map<int, int> cnt;
		scanf("%d", &N);
		for (int i = 0; i < 2*N-1; i++) {
			for (int j = 0; j < N; j++) {
				int a;
				scanf("%d", &a);
				cnt[a]  ++;
			}
		}
		for (auto p : cnt) {
			if (p.second % 2 == 1) sol.push_back(p.first);
		}
		sort(sol.begin(), sol.end());
		printf("Case #%d:", tc);
		for (int i = 0; i < N; i++) printf(" %d", sol[i]);
		printf("\n");
	}
	return 0;
}