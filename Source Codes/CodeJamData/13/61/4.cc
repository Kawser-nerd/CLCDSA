#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long long C, X, N;
long long cs[1001], ce[1001], ct[1001];
long long ret;

void doit(long long t, long long x) {
//cout << x+1 << '@' << t;
	long long t1 = 0, t2 = X;
	x = (x+t)%N;
	for (long long i = 0; i < C; i++) {
		long long st = ct[i];
		long long et = ct[i] + (ce[i]+N-cs[i])%N;
		long long p1 = ((x-st)%N+N)%N;
		long long p2 = ((x-et)%N+N)%N;
		long long s = cs[i];
		long long e = ce[i];
		while (e < s) e += N;
		while (p2 > p1) p2 -= N;
		while (p1 < e) {p1 += N; p2 += N;}
		long long clash1a = -1, clash1b = -1, clash2a = -1, clash2b = -1;
		if (p2 <= e) {
			clash2a = et - (e-p2+1)/2;
			clash2b = et - (e-p2)/2;
			if (clash2a == clash2b && clash2a == t) return;
		}
		while (p2 > s) {p1 -= N; p2 -= N;}
		if (p1 >= s) {
			clash1a = st + (p1-s)/2;
			clash1b = st + (p1-s+1)/2;
			if (clash1a == clash1b && clash1a == t) return;
		}
		if (clash1a != -1) {
			if (t <= clash1a) t2 = min(t2, clash1a - (clash1a == clash1b));
			else t1 = max(t1, clash1b + (clash1a == clash1b));
		}
		if (clash2a != -1) {
			if (t <= clash2a) t2 = min(t2, clash2a - (clash2a == clash2b));
			else t1 = max(t1, clash2b + (clash2a == clash2b));
		}
	}
//cout << ' ' << t1 << ' ' << t2 << endl;
	ret = max(ret, t2-t1);
}

main() {
	long long T, prob=1;
	for (cin >> T; T--;) {
		cin >> C >> X >> N;
		for (long long i = 0; i < C; i++) {
			cin >> cs[i] >> ce[i] >> ct[i];
			cs[i]--; ce[i]--;
		}
		ret = 0;
		doit(0, 0);
		doit(X, 0);
		for (long long i = 0; i < C; i++) {
			doit(ct[i], (cs[i]+(N-1))%N);
			doit(ct[i], (cs[i]+(N-2))%N);
			doit(ct[i] + (ce[i]+N-cs[i])%N, (ce[i]+1)%N);
			doit(ct[i] + (ce[i]+N-cs[i])%N, (ce[i]+2)%N);
		}
		cout << "Case #" << prob++ << ": " << ret << endl;
	}
}
