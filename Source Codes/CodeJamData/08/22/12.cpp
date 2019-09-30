#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

typedef long long i64;

bool _p[10000000];
int pr[10000000];
int r[10000000];
int p[10000000];

int getp(int x) {
	if (pr[x] != x) pr[x] = getp(pr[x]);
	return pr[x];
}

inline void merge(int x, int y) {
	x = getp(x); y = getp(y);
	if (r[x] > r[y]) pr[y] = x;
	else if (r[y] > r[x]) pr[x] = y;
	else {
		pr[y] = x;
		++r[x];
	}
}

int main() {
	int T; scanf("%d", &T);
	int pc = 0;
	for (int i = 2; i <= 2000000; ++i) if (!_p[i]) {
		p[pc++] = i;
		if (2000000 / i < i) continue;
		for (int j = i * i; j <= 2000000; j += i) {
			_p[j] = true;
		}
	}
	for (int tt = 0; tt < T; ++tt) {
		i64 A, B, P;
		cin >> A >> B >> P;
		for (i64 i = A; i <= B; ++i) {
			pr[i - A] = i - A;
			r[i - A] = 0;
			
		}
		for (int i = 0; (i < pc) && (p[i] <= B); ++i) {
			if (p[i] < P) continue;
//			cout << p[i] << ": ";
			i64 s = (A / p[i]) * p[i];
			while (s < A) s += p[i];
			while (s <= B) {
//				cout << s << " ";
				i64 ss = s + p[i];
				if (ss <= B) {
//					cout << s << " " << ss << endl;
					merge(s - A, ss - A);
//					cout << getp(975 - A) << " " << getp(988 - A) << endl;
				}
				s = ss;
			}
//			cout << endl;
		}
//		cout << P << endl;
		for (i64 i = A; i <= B; ++i) {
			pr[i - A] = getp(i - A);
//			cout << i << " " << pr[i - A] << endl;
		}
		sort(pr, pr + B - A + 1);
		int result = unique(pr, pr + B - A + 1) - pr;
		printf("Case #%d: ", tt + 1);
		cout << result << endl;
	}
	return 0;
}
