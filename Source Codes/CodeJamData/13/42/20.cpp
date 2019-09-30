#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cases, n;
long long p;

void run() {
    scanf("%d %lld", &n, &p);
    long long ans1, ans2;

    int k = 0; long long e = 1;
    while (e * 2 <= p) {
	++k;
	e *= 2;
    }
    ans2 = (1LL << n) - (1LL << (n - k));

    long long l = 0, r = (1LL << n);
    while (l < r) {
	long long mid = (l + r) / 2;
	
	k = 0; e = 1;
	long long rank = 0;
	while (e * 2 <= mid + 1) {
	    e *= 2;
	    k += 1;
	    rank += 1LL << (n - k);
	}
	if (rank + 1 <= p) l = mid + 1;
	else r = mid;
    }
    ans1 = l - 1;

    printf("%lld %lld\n", ans1, ans2);
}

int main() {
    scanf("%d", &cases);
    for (int ca = 1; ca <= cases; ++ca) {
	printf("Case #%d: ", ca);
	run();
    }	
}
