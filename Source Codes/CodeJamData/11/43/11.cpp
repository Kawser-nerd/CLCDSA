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

const int SIZE = 1<<20;

bool npr[SIZE];

int64 n;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	npr[0] = npr[1] = true;
	for (int i = 2; i*i<SIZE; i++) if (!npr[i])
		for (int j = i*i; j<SIZE; j+=i)
			npr[j] = true;

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%I64d", &n);
		
		int64 ans = 0;
		if (n > 1) {
			int i;
			for (i = 2; int64(i)*i<=n; i++) if (!npr[i]) {
				int64 x = 1;
				while (x <= n / i) {
					x *= i;
					ans++;
				}
				ans--;
			}
			ans++;
		}

		printf("Case #%d: %I64d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
