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
#define taskname "task_b"
const ldb pi = acos(-1.0);
int t, ans, n;

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		ans = 0;
		for (int i = 0; i < n; ++i) {
			int pos = min_element(a.begin(), a.end()) - a.begin();
			ans += min(pos, sz(a) - 1 - pos);
			a.erase(a.begin() + pos);
		}
		printf("Case #%d: %d\n", it + 1, ans);
	}
	return 0;
}

