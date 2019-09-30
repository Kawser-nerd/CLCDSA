#include <bits/stdc++.h>
using namespace std;

int TC, N, P, T[55];
deque< pair<int, int> > ranges[55];

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d%d", &N, &P);
		for (int i = 0; i < N; i++) ranges[i].clear();
		for (int i = 0; i < N; i++) scanf("%d", &T[i]);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < P; j++) {
				int x;
				scanf("%d", &x);
				int k1 = int((double)(x - 1) / T[i] / 1.1) + 1;
				int k2 = (double)x / T[i] / 0.9;
				k1 = max(1, k1);
				if (k1 <= k2) ranges[i].push_back(make_pair(k1, k2));
			}
		}
		for (int i = 0; i < N; i++) sort(ranges[i].begin(), ranges[i].end());
		int ans = 0;
		while (1) {
			int ls = 0, ee = 1000000000, picked = -1;
			bool flag = 0;
			for (int i = 0; i < N; i++) {
				if (ranges[i].size() == 0) {
					flag = 1;
					break;
				}
				ls = max(ls, ranges[i][0].first);
				if (ranges[i][0].second < ee) {
					ee = ranges[i][0].second;
					picked = i;
				}
			}
			if (flag) break;
			if (ls <= ee) {
				ans++;
				for (int i = 0; i < N; i++) ranges[i].pop_front();
			} else {
				ranges[picked].pop_front();
			}
		}
		printf("Case #%d: %d\n", tc, ans);
	}
}
