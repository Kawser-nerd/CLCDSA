#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX_N = 15;

char type[MAX_N];
int id[MAX_N];

int dp[1 << MAX_N], n;
int can[1 << MAX_N];

int checkSet(int set) {
	int have = 0;
	for (int i = 0; i < n; ++i) {
		if ((set >> i & 1) && id[i] > 0)
			have = id[i];
	}

	if (have > 0) {
		for (int i = 0; i < n; ++i) {
			if ((set >> i & 1) && id[i] > 0 && id[i] != have)
				return -1;
			if ((~set >> i & 1) && id[i] > 0 && id[i] == have)
				return -1;
		}
	}

	char should = '?';
	for (int i = 0; i < n; ++i) {
		if (set >> i & 1) {
			if (should == '?')
				should = type[i];
			if (type[i] != should)
				return -1;
			if (should == 'E')
				should = 'L';
			else
				should = 'E';
		}
	}

	if (should == 'L')
		return 1;
	else
		return 0;
}

const int INF = ~0U >> 2;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		cin >> n;
		scanf(" ");
		for (int i = 0; i < n; ++i) {
			cin >> type[i] >> id[i];
		}

//		cout << "N:" << n << endl;

		for (int set = 1; set < (1 << n); ++set) {
			can[set] = checkSet(set);
//			if (can[set] != -1 && n < 5) {
//				cout << set << endl;
//			}
		}

		for (int i = 0; i < (1 << n); ++i) {
			dp[i] = INF;
		}
		dp[0] = 0;
		for (int i = 1; i < (1 << n); ++i) {
			for (int j = i; j > 0; (--j) &= i)
				if (can[j] != -1)
					dp[i] = min(dp[i], dp[i - j] + can[j]);
		}
		int ans = dp[(1 << n) - 1];
		if (ans == INF) {
			puts("CRIME TIME");
		} else {
			printf("%d\n", ans);
		}
	}
}
