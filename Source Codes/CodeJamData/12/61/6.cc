#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Z, Zx[101], Zy[101], Zt[101];

int memo[101][1001];
int doit(int z, int t) {
	int& ret = memo[z][t - Zt[z]];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < Z; i++) if (i != z) {
		int mt = max(abs(Zx[i]-Zx[z]), abs(Zy[i]-Zy[z]))*100;
		if (z != Z) mt = max(mt, 750);
		if (t+mt <= Zt[i]+1000) {
			ret = max(ret, 1 + doit(i, max(Zt[i], t+mt)));
		}
	}
	return ret;
}

main() {
	int T, prob = 1;
	for (cin >> T; T--;) {
		cin >> Z;
		for (int i = 0; i < Z; i++) cin >> Zx[i] >> Zy[i] >> Zt[i];
		Zx[Z] = Zy[Z] = Zt[Z] = 0;
		memset(memo, -1, sizeof(memo));
		int ret = doit(Z, 0);
		cout << "Case #" << prob++ << ": " << ret << endl;
	}
}
