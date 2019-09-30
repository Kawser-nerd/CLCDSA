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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

#include "longint.h"

LongInteger gcd(LongInteger a, LongInteger b) {
	return b.GetSign() == 0 ? a : gcd(b, a % b);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		int64 sp, sq;
		scanf("%I64d/%I64d", &sp, &sq);

		LongInteger p = sp, q = sq;
		LongInteger g = gcd(p, q);
		p /= g;  q /= g;
		if (LongInteger(1LL<<40) % q != LongInteger(0))
			printf("Case #%d: impossible\n", tt);
		else {
			LongInteger t = (LongInteger(1LL<<40) / q) * p;
			int mx = 0;
			while (LongInteger(1LL<<mx) <= t) mx++;
			mx--;
			printf("Case #%d: %d\n", tt, 40 - mx);
		}
		fflush(stdout);
	}
	return 0;
}
