#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int size = 10 * 1000;

double hp[size][size];

int main() {
	int n, x, y, tc;

	freopen("problem_b.in", "r", stdin);
	freopen("problem_b.out", "w", stdout);
	
	scanf("%d", &tc);
	for (int tnum = 0; tnum < tc; tnum++) {
		scanf("%d%d%d", &n, &x, &y);
		int level;
		level = (abs(x) + y) / 2;
		int ls = 1;
		for (int i = 0; i < level; i++) {
			n -= ls;
			ls += 4;
		}

		double ans;
		if (n >= ls)
			ans = 1.0;
		else
			if (n < 0 || x == 0)
				ans = 0.0;
			else {
				ans = 0.0;
				int lm = (ls - 1) / 2;
				for (int i = 0; i <= lm; i++)
					for (int j = 0; j <= lm; j++)
						hp[i][j] = 0.0;
				hp[0][0] = 1.0;
				for (int i = 0; i <= lm; i++)
					for (int j = 0; j <= lm; j++) {
						if (i < lm && j < lm) {
							hp[i + 1][j] += hp[i][j] * 0.5;
							hp[i][j + 1] += hp[i][j] * 0.5;
						}
						if (i < lm && j == lm)
							hp[i + 1][j] += hp[i][j];
						if (i == lm && j < lm)
							hp[i][j + 1] += hp[i][j];
						if (i > y && i + j == n)
							ans += hp[i][j];
					}
			}

		cout.precision(20);
		cout << "Case #" << tnum + 1 << ": " << ans << endl;
	}

	return 0;
}