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

const int SIZE = 20;
const int PROF = 1<<SIZE;

int n;
double res[PROF];
char str[SIZE*2];
int start;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%s", str);
		n = strlen(str);
		start = 0;
		for (int i = 0; i<n; i++)
			if (str[i] == 'X')
				start |= (1<<i);

		for (int p = (1<<n)-1; p>=start; p--) {
			if (p == (1<<n)-1) {
				res[p] = 0.0;
				continue;
			}
			double tres = 0.0;
			for (int j = 0; j<n; j++) {
				int u = j;
				int w = 0;
				while (p & (1<<u)) {
					w++;
					u++;
					if (u == n) u = 0;
				}
				tres += res[p ^ (1<<u)] + (n-w);
			}
			tres /= n;
			res[p] = tres;
		}

		printf("Case #%d: %0.15lf\n", tt, res[start]);
		fflush(stdout);
	}
	return 0;
}
