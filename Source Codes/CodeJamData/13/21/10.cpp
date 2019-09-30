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

const int MAXN = 1024;

int a, n;
int arr[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d", &a, &n);
		for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

		sort(arr, arr+n);

		int ans = 1000000000;
		for (int rem = 0; rem<=n; rem++) {
			int q = n - rem;

			int curr = a;
			int added = 0;
			for (int i = 0; i<q; i++) {
				while (curr <= arr[i]) {
					if (curr == 1) {
						added += 1000000000;
						break;
					}
					curr += curr-1;
					added++;
				}
				if (added >= 1000000000) break;
				assert(added < 200000000);

				assert(curr > arr[i]);
				curr += arr[i];
			}

			int score = added + rem;
			ans = min(ans, score);
		}

		printf("Case #%d: %d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
