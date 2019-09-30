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

const int SIZE = 10<<10;
const double EPS = 1e-6;

int n, love;
int pos[SIZE], len[SIZE];
double res[SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d", &n);
		for (int i = 0; i<n; i++) scanf("%d%d", &pos[i], &len[i]);
		scanf("%d", &love);
		
		bool ans = false;
		for (int i = 0; i<n; i++) res[i] = -1e+50;

		res[0] = pos[0];
		for (int i = 0; i<n; i++) if (res[i] > EPS) {
			double reach = pos[i] + res[i];
			if (reach >= love - EPS) ans = true;

			for (int j = i+1; j<n; j++) {
				if (pos[j] > reach + EPS) break;
				double dx = pos[j] - pos[i];
				double sqrtof = res[i]*res[i] - dx*dx;
				double hgt = sqrt(max(sqrtof, 0.0));
				hgt = min(hgt, 0.0+len[j]);
				hgt = max(hgt, dx);
				hgt = min(hgt, 0.0+len[j]);

				if (res[j] < hgt) res[j] = hgt;
			}
		}

//		for (int i = 0; i<n; i++) printf("%d[%d] -> %0.9lf\n", i, pos[i], res[i]);

		printf("Case #%d: %s\n", tt, (ans ? "YES" : "NO"));
		fflush(stdout);
	}
	return 0;
}
