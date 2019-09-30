#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2000;
const int h = 1000002013;
int l[N], r[N], p[N];
int cases, n, m;
map<int, long long> up;
map<int, long long> down;


long long min(long long a, long long b) {
    return (a < b)? a : b;
}

void run() {
    scanf("%d %d", &n, &m);
    up.clear();
    down.clear();
    long long lastans = 0, nowans = 0;
    for (int i = 1; i <= m; i++) {
	scanf("%d %d %d", &l[i], &r[i], &p[i]);
	up[l[i]] += p[i];
	down[r[i]] += p[i];

	long long d = r[i] - l[i] + 1;
	long long charge = (d * d + d - 2) / 2;
	long long tot = charge % h * p[i] % h;
	lastans = (lastans + tot) % h;
    }

    map<int, long long>::iterator it1, it2;
    for (it1 = down.begin(); it1 != down.end(); it1++) {
	it2 = up.end();
	do {
	    it2--;
	    if (it2->first > it1->first) continue;

	    long long num = min(it1->second, it2->second);
	    long long d = it1->first - it2->first + 1;
	    long long charge = (d * d + d - 2) / 2;
	    long long tot = charge % h * num % h;
	    nowans = (nowans + tot) % h;

	    it1->second -= num;
	    it2->second -= num;
	    if (it1->second == 0) break;
	} while (it2 != up.begin());
    }

    int ans = (nowans - lastans + h) % h;
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &cases);
    for (int ca = 1; ca <= cases; ++ca) {
	printf("Case #%d: ", ca);
	run();
    }	
}
