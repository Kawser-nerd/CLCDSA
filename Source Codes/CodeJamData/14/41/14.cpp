#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_a"
const ldb pi = acos(-1.0);
int n, x, t, ans, size, cnt[701];

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d", &n, &size);
		assert(size <= 700);
		for (int i = 0; i <= size; ++i)
			cnt[i] = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &x), cnt[x]++;
		ans = 0;
		for (int i = size; i >= 0; --i)
			while (cnt[i] > 0) {
				++ans, --cnt[i];
				for (int j = i; j >= 0; --j)
					if ((cnt[j] > 0) && (i + j <= size)) {
						--cnt[j];
						break;
					}
			}
		printf("Case #%d: %d\n", it + 1, ans);
	}
	return 0;
}

