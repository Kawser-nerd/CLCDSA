#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 1010
int n, C, m;
int a[N], b[N];

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> C >> m;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 0; i < m; i ++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			b[y] ++;
			a[x] ++;
		}
		int S = 0;
		for (int i = 0; i < C; i ++)
			S = max(S, b[i]);
		int s = 0;
		for (int i = 0; i < n; i ++) {
			s += a[i];
			S = max(S, (s-1)/(i+1)+1);
		}
		int T = 0;
		for (int i = 0; i < n; i ++)
			T += max(0, a[i]-S);
		printf ("Case #%d: %d %d\n", __, S, T);
	}
	return 0;
}