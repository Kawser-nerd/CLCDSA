#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

#define sqr(a) ((a)*(a))
#define has(mask,a) (((mask) & (1 << (a))) ? 1 : 0)

int n, a, p[15];

string s[15];

void load() {
	cin >> n >> a;
	for (int i = 0;i < n;i++) {
		cin >> s[i];
	}
}

void solve (int test) {
	printf ("Case #%d: ", test);
	for (int i = 0;i < n;i++) {
		p[i] = i;
	}

	do {
		int cur = p[0];
		for (int i = 1;i < n;i++) {
			if (s[cur][p[i]] == 'N') cur = p[i]; 
		}

		if (cur == a) {
			for (int i = 0;i < n;i++) {
				printf ("%d", p[i]);
				if (i < n - 1) printf (" ");
			}
			cout << endl;
			return;
		}

	} while (next_permutation (p, p + n));
	printf ("IMPOSSIBLE\n");
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 0;i < t;i++) {
 		cerr << i << endl;
 		load();
 		solve(i + 1);
 	}
}
