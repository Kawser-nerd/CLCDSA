#include <map>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int Test, R, C, W;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &Test);
	for (int Case = 1; Case <= Test; Case ++) {
		scanf("%d%d%d", &R, &C, &W);
		int Ret = R * (C / W);
		if (C % W == 0) {
			Ret += (W - 1);
		} else {
			Ret += W;
		}
		printf("Case #%d: %d\n", Case, Ret);
	}
    return 0;
}

