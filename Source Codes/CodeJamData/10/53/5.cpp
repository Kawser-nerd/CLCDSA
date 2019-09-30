#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int ADD = 1200000;

const int MX = 2500000;

typedef long long LL;

int n;

int t[MX + 5];

int s[MX + 5], ss;

int curHole;

LL sum(int n) {
	return (LL(n) * (n + 1)) / 2;
}

LL countMoves(int dist, int cMoves) {
	return sum(dist) - sum(dist - cMoves);
}


void alg() {
	memset(t, 0, sizeof(t));
	LL res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, c;
		scanf("%d %d", &x, &c);
		t[x + ADD] += c;
	}
	ss = 0;
	curHole = -1;
	for (int x = 1; x <= MX; ++x) {
		if (t[x] == 0) {
			s[ss++] = x;
			continue;
		}
		curHole = s[--ss];
		while (t[x] > 1) {
			int moves = min(x - curHole, t[x] - 1);
			res += countMoves(x - curHole, moves);
			t[x + 1] += moves;
			t[x] -= moves;
			curHole += moves;
			if (curHole == x) {
				--t[x];
				if (t[x] != 0) {
					curHole = s[--ss];
				}
			}
		}
		s[ss++] = curHole;
	}
	printf("%lld\n", res);
}

int main() {
	int d;
	scanf("%d", &d);
	for (int caseNo = 1; caseNo <= d; ++caseNo) {
		printf("Case #%d: ", caseNo);
		alg();
	}
}
