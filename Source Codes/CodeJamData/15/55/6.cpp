#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

const int MAXN = 60;

int n, D;
int d[MAXN];

bool check(int k) {
	if (k == 0) {
		forab(i, 1, n)
			if (d[i] != d[i - 1])
				return false;
		return true;
	}

	for(int z = 0; (1 << z) <= D; z++)
		forn(st, 2)
			forn(q, (1 << z)) {
				bool good = true;
				
				bool delta = st;
				int sch = q;
				forn(i, n) {
					if (delta)
						d[i]--;
					if (d[i] < 0)
						good = false;
					sch++;
					if (sch == (1 << z)) {
						sch = 0;
						delta = !delta;
					}
				}

				if (good && check(k - 1))
					return true;

				delta = st;
				sch = q;
				forn(i, n) {
					if (delta)
						d[i]++;
					sch++;
					if (sch == (1 << z)) {
						sch = 0;
						delta = !delta;
					}
				}				
			}

	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	scanf("%d ", &T);
	forn(test, T) {
		cerr << test << '\n';

		printf("Case #%d: ", test + 1);

		scanf("%d%d", &n, &D);
		forn(i, n)
			scanf("%d", &d[i]);

		int ans = -1;
		forn(i, 8)
			if (check(i)) {
				ans = i;
				break;
			}

		if (ans == -1)
			printf("CHEATERS!\n");
		else
			printf("%d\n", ans);

	}
	return 0;
}
