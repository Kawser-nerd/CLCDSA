// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;
typedef pair<short, int> PCI;

long long gcd(long long a, long long b) {
	return b? gcd(b, a%b) : a;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d: ", scen);
		long long n;
		int pd, pg;
		scanf("%lld %d %d", &n, &pd, &pg);
		if (pg == 0 && pd > 0) {
			puts("Broken");
			continue;
		}
		if (pg == 0) {
			puts("Possible");
			continue;
		}
		if (pg == 100 && pd < 100) {
			puts("Broken");
			continue;
		}
		bool possible = false;
		// stops after at most 100 steps
		for (int i=1; i<=n && !possible; ++i) {
			if ((i * pd) % 100 == 0) {
				possible = true;
				/*
				// check if pg can be reached by adding x losses, y wins
				int wins_today = i * pd / 100;
				// (wins_today + y) / (i + x + y) = pg / 100
				// pg / 100 * (i + y) + pg / 100 * x = (wins_today + y)
				// x = wins_today * 100 / pg + y * 100 / pg + (i + y)
				for (int y=0; y<=10000; ++y) {
					if ((wins_today + y)*100 % pg != 0) continue;
					int x = (wins_today + y) * 100 / pg - i - y;
					if (x >= 0) {
						possible = true;
						break;
					}
				}
				*/
			}
		}
		puts(possible?"Possible":"Broken");
	}
	return 0;
}
