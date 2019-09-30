#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>

typedef long long LL;
class HIKER {
public:
	HIKER() {}
	HIKER(int d, int m, LL nn, int p) : d(d), m(m), nn(nn), p(p) {}
	int d, m;
	LL nn;
	int p;
	
	const bool operator < (const HIKER &h) const {
		return nn > h.nn;
	}
};
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		int N;
		scanf("%d", &N);
		priority_queue<HIKER> Q;
		int sol = 0;
		int su = 0;
		for (int i = 0; i < N; i++) {
			int d, h, m;
			scanf("%d %d %d", &d, &h, &m);
			for (int j = 0; j < h; j++) {
				int ld = 360 - d;
				int mm = m + j;
				LL nn = (LL)ld * (LL)mm;
				Q.push(HIKER(d, mm, nn, 1));
				su++;
			}
		}

		int now = su;
		sol = su;

		LL before = 0ll;
		while (now < su * 2) {
			HIKER h = Q.top();
			Q.pop();
			if (before != h.nn) {
				if (sol > now) sol = now;
				before = h.nn;
			}

			h.nn += h.m * 360ll;
			if (h.p == 1) {
				h.p = 0;
				now--;
			}
			else {
				now++;
			}
			Q.push(h);
		}

		printf("Case #%d: %d\n", cs, sol);
	}
	
	return 0;
}