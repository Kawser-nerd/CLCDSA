#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 4096;

int n;
int arr[SIZE];
int ans[SIZE];

bool Solve(int left, int right, int lhgt, int rhgt) {
	vector<int> chain;

	int curr = left;
	while (curr < right) {
		chain.push_back(curr);
		curr = arr[curr];
	}
	if (curr > right) return false;

    int fk = (rhgt - lhgt) / (right - left + 1);
    int tk = fk + 1;

    int s = chain.size();
    chain.push_back(right);
    for (int i = 0; i<s; i++)
    	ans[chain[i]] = rhgt - (right - chain[i]) * tk;

	for (int i = 0; i<s; i++) {
		int sonl = chain[i] + 1;
		int sonr = chain[i+1];
		if (sonr - sonl <= 0) continue;

		bool qq = Solve(sonl, sonr, ans[sonl-1], ans[sonr]);
		if (!qq) return false;
	}

	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d", &n);
		for (int i = 0; i<n-1; i++) {
			scanf("%d", &arr[i]);
			arr[i]--;
		}
		arr[n-1] = n;

		memset(ans, 0, sizeof(ans));
		bool ok = Solve(0, n, 0, 0);

		printf("Case #%d:", tt);
		if (!ok) printf(" Impossible");
		else {
			int minh = 0;
			for (int i = 0; i<n; i++) minh = min(minh, ans[i]);
			for (int i = 0; i<n; i++) {
				int q = ans[i] - minh;
				assert(q >= 0 && q <= 1000000000);
				printf(" %d", ans[i] - minh);
			}
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
