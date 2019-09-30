#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int n, k;
		cin >> n >> k;
		int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
		for (int i = 0; i < n; i ++) {
			int x;
			cin >> x;
			if (x%k == 0) c0++; else
			if (x%k == 1) c1++; else
			if (x%k == 2) c2++; else
			if (x%k == 3) c3++;
		}
		int S = 0;
		if (k == 2) {
			S = c0+c1/2+1;
			if (c1%2 == 0) S--;
		} else
		if (k == 3) {
			for (int i = 0; i <= c1 && i <= c2; i ++) {
				int T = 1 + c0 + i + (c1-i)/3 + (c2-i)/3;
				if ((c1-i)%3 == 0 && (c2-i)%3 == 0) T--;
				S = max(S, T);
			}
		} else
		if (k == 4) {
			for (int i = 0; i <= c1 && i <= c3; i ++) {
				int T = 1 + c0 + c2/2 + i + (c1-i)/4 + (c3-i)/4;
				if (c2%2 == 0 && (c1-i)%4 == 0 && (c3-i)%4 == 0) T--;
				S = max(S, T);
			}
		}
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}