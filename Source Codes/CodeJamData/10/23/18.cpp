#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long i64;

const int MAXN = 510;
const i64 P = 100003;
i64 d[MAXN + 1][MAXN + 1];
i64 a[MAXN + 1];
i64 C[MAXN + 1][MAXN + 1];

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i <= MAXN; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
		}
	}
	
	for (int i = 2; i <= MAXN; ++i) {
		d[i][1] = 1;
		a[i] = 1;
		for (int j = 2; j < i; ++j) {
			d[i][j] = 0;
			for (int k = 1; k < j; ++k) {
				d[i][j] = (d[i][j] + d[j][k] * C[i - j - 1][j - k - 1]) % P;
			}
// 			cout<< d[i][j] << " ";
			a[i] = (a[i] + d[i][j]) % P;
		}
// 		cout << endl;
//		cout << i << " " << a[i] << endl;
	}
	for (int tt = 0; tt < T; ++tt) {
		int n; scanf("%d", &n);
		printf("Case #%d: %lld\n", tt + 1, a[n]);
	}
	return 0;
}
