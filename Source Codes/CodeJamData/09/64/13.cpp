#include <stdio.h>
#include <vector>
using namespace std;

bool inRange[512][512];
int s[512];
int n;

bool ok(int mask) {
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (((mask>>i)&1)!=0 && ((mask>>j)&1)==0 && inRange[i][j])
				return false;
	return true;
}

int getScore(int mask) {
	int res = 0;
	for (int i=0; i<n; i++)
		if ((mask>>i)&1)
			res += s[i];
	return res;
}

long long sqr(long long x) {
	return x*x;
}

int runTest() {
	int x[512], y[512], r[512];
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d%d%d%d", x+i, y+i, r+i, s+i);
	int best = -1000000000;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			inRange[i][j] = sqr(x[i]-x[j])+sqr(y[i]-y[j])<=sqr(r[i]);
	for (int mask=0; mask<(1<<n); mask++)
		if (ok(mask)) {
			int score = getScore(mask);
			if (score>best)
				best = score;
		}
	return best; 
}

int main() {
	int T;
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
		printf("Case #%d: %d\n", t, runTest());
	return 0;
}
