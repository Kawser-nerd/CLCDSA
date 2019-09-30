#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, P, K, L;

int main() {
	scanf("%d", &N);
	for (int case_n = 1; case_n <= N; case_n++) {
		scanf("%d%d%d", &P, &K, &L);
		vector<int> keys; keys.clear();
		for (int i = 0; i < L; i++) {
			int x;
			scanf("%d", &x);
			keys.push_back(x);
		}
		sort(keys.rbegin(), keys.rend());
		int sum = 0;
		for (int i = 0; i < keys.size(); i++) {
			sum += keys[i] * (i / K + 1);
		}
		printf("Case #%d: %d\n", case_n, sum);
	}
	return 0;
}